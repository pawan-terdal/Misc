set ns [new Simulator]
set f [open 2-out.tr w]
set nf [open 2-out.nam w]

$ns trace-all $f
$ns namtrace-all $nf

proc finish {} {
  global ns f nf
  $ns flush-trace
  close $f
  close $nf
  exec awk -f 2-script.awk 2-out.tr > 2-out.txt
  exec nam 2-out.nam
  exit 0
}

set n0 [$ns node]
set n1 [$ns node]
set n2 [$ns node]
set n3 [$ns node]
set n4 [$ns node]
set n5 [$ns node]

$ns duplex-link $n0 $n2 4Mb 5ms DropTail
$ns duplex-link $n1 $n2 4Mb 5ms DropTail
$ns duplex-link $n2 $n3 4Mb 15ms DropTail
$ns duplex-link $n3 $n4 4Mb 5ms DropTail
$ns duplex-link $n3 $n5 4Mb 5ms DropTail

set ping0 [new Agent/Ping]
set ping1 [new Agent/Ping]
set ping4 [new Agent/Ping]
set ping5 [new Agent/Ping]

$ns attach-agent $n0 $ping0
$ns attach-agent $n1 $ping1
$ns attach-agent $n4 $ping4
$ns attach-agent $n5 $ping5

$ns connect $ping0 $ping5
$ns connect $ping1 $ping4

proc keepPinging {} {
  global ns ping0 ping1
  set intervalTime 0.001
  set now [$ns now]
  $ns at [expr $now + $intervalTime] "$ping0 send"
  $ns at [expr $now + $intervalTime] "$ping1 send"
  if {$now > 1.00} {
    return
  }
  $ns at [expr $now + $intervalTime] "keepPinging"
  return
}

set seq 1
Agent/Ping instproc recv {from rtt} {
  global seq
  $self instvar node_
  puts "64 bytes from[$node_ id] icmp_seq=$seq ttl=64 time=$rtt ms" 
  set seq [expr $seq+1] 
}

$ns at 0.1 "keepPinging"
$ns rtmodel-at 0.5 down $n1 $n2
$ns at 2 "finish"
$ns run
