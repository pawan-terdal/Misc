set ns [new Simulator]
set file [open 3-out.tr w]
set namfile [open 3-out.nam w]

$ns trace-all $file
$ns namtrace-all $namfile

proc finish {} {
    global ns file namfile
    $ns flush-trace
    close $file
    close $namfile
    exec awk -f 3-script.awk 3-out2.tr > 3-out2.txt &
    exec awk -f 3-script.awk 3-out1.tr > 3-out1.txt &
    exec nam 3-out.nam &
    exec xgraph 3-out1.txt 3-out2.txt &
    exit 0
}

set n0 [$ns node]
set n1 [$ns node]
set n2 [$ns node]
set n3 [$ns node]
set n4 [$ns node]
set n5 [$ns node]
set n6 [$ns node]
set n7 [$ns node]

$ns make-lan "$n0 $n1 $n2 $n3" 10Mb 100ms LL Queue/DropTail Mac/802_3
$ns make-lan "$n4 $n5 $n6 $n7" 10Mb 50ms LL Queue/DropTail Mac/802_3
$ns duplex-link $n2 $n4 1Mb 50ms DropTail

$ns duplex-link-op $n2 $n4 orient right

set tcp1 [new Agent/TCP]
set sink1 [new Agent/TCPSink]
set ftp1 [new Application/FTP]
$tcp1 set fid_ 1
$ns color 1 red

$ns attach-agent $n0 $tcp1
$ns attach-agent $n5 $sink1
$ns connect $tcp1 $sink1
$ftp1 attach-agent $tcp1

set tcp2 [new Agent/TCP]
set sink2 [new Agent/TCPSink]
set ftp2 [new Application/FTP]
$tcp2 set fid_ 2
$ns color 2 blue

$ns attach-agent $n1 $tcp2
$ns attach-agent $n3 $sink2
$ns connect $tcp2 $sink2
$ftp2 attach-agent $tcp2

set f1 [open 3-out1.tr w]
set f2 [open 3-out2.tr w]
$tcp1 attach $f1
$tcp2 attach $f2

$tcp1 trace cwnd_
$tcp2 trace cwnd_

$ns at 0 "$ftp1 start"
$ns at 3 "$ftp1 stop"
$ns at 4 "$ftp2 start"
$ns at 6 "$ftp1 start"
$ns at 8 "$ftp2 stop"
$ns at 10 "$ftp1 stop"
$ns at 20.0 "finish"
$ns run
