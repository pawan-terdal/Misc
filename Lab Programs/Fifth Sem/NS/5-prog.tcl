set ns [new Simulator]
set f [open 5-out.tr w]
set nf [open 5-out.nam w]
$ns trace-all $f
$ns namtrace-all $nf

proc finish {} { 
  global nodes ns f nf
  $ns flush-trace
  close $f
  close $nf
  exec awk -f 5-script.awk 5-out.tr > 5-out.txt
  exec nam 5-out.nam &
  exit 0
}

set opt(ecn) 0 ;
set opt(window) 30 ; 
set opt(type) gsm ; # umts
set opt(minth) 5 ; 
set opt(maxth) 10 ; 
set opt(adaptive) 1 ; 

set bwDL($opt(type)) 80K ;  # 450K 
set bwUL($opt(type)) 80K ; # 450K
set propDL($opt(type)) .500 ; # .150
set propUL($opt(type)) .500 ; # .150
set buf($opt(type)) 10 ;

set nodes(s) [$ns node]
set nodes(bs1) [$ns node]
set nodes(ms) [$ns node]
set nodes(bs2) [$ns node]
set nodes(d) [$ns node]

$ns duplex-link $nodes(s) $nodes(bs1) 3Mbps 10ms DropTail
$ns duplex-link $nodes(bs1) $nodes(ms) 1Mbps 1ms RED
$ns duplex-link $nodes(ms) $nodes(bs2) 1Mbps 1ms RED
$ns duplex-link $nodes(bs2) $nodes(d) 3Mbps 50ms DropTail

$ns bandwidth $nodes(bs1) $nodes(ms) $bwUL($opt(type)) simplex
$ns bandwidth $nodes(ms) $nodes(bs1) $bwDL($opt(type)) simplex
$ns bandwidth $nodes(bs2) $nodes(ms) $bwUL($opt(type)) simplex
$ns bandwidth $nodes(ms) $nodes(bs2) $bwDL($opt(type)) simplex
$ns delay $nodes(bs1) $nodes(ms) $propUL($opt(type)) simplex
$ns delay $nodes(ms) $nodes(bs1) $propDL($opt(type)) simplex
$ns delay $nodes(bs2) $nodes(ms) $propUL($opt(type)) simplex
$ns delay $nodes(ms) $nodes(bs2) $propDL($opt(type)) simplex
$ns queue-limit $nodes(bs1) $nodes(ms) $buf($opt(type))
$ns queue-limit $nodes(ms) $nodes(bs1) $buf($opt(type))
$ns queue-limit $nodes(bs2) $nodes(ms) $buf($opt(type))
$ns queue-limit $nodes(ms) $nodes(bs2) $buf($opt(type))


Queue/DropTail set summarystats_ true
Queue/DropTail set shrink_drops_ true

Queue/RED set summarystats_ true
Queue/RED set q_weight_ 0.0
Queue/RED set thresh_ $opt(minth)
Queue/RED set maxthresh_ $opt(maxth)
Queue/RED set adaptive_ $opt(adaptive)

Agent/TCP set ecn_ $opt(ecn)
Agent/TCP set window_ $opt(window)
DelayLink set avoidReordering_ true


$ns insert-delayer $nodes(ms) $nodes(bs1) [new Delayer]
$ns insert-delayer $nodes(bs1) $nodes(ms) [new Delayer]
$ns insert-delayer $nodes(ms) $nodes(bs2) [new Delayer]
$ns insert-delayer $nodes(bs2) $nodes(ms) [new Delayer]

# Set up forward TCP connection
set tcp1 [$ns create-connection TCP/Sack1 $nodes(s) TCPSink/Sack1 $nodes(d) 0]
set ftp1 [[set tcp1] attach-app FTP]

$ns at 0.5 "$ftp1 start"
$ns at 100 "finish"
$ns run