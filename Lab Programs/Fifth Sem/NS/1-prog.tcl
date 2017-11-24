set ns [new Simulator]
set file [open 1-out.tr w]
set namfile [open 1-out.nam w]

$ns trace-all $file
$ns namtrace-all $namfile

proc finish {} {
    global ns file namfile
    $ns flush-trace
    close $file
    close $namfile
    exec awk -f 1-script.awk 1-out.tr > 1-out.txt
    exec nam 1-out.nam
    exit 0
}

set n0 [$ns node]
set n1 [$ns node]
set n2 [$ns node]
set n3 [$ns node]

$ns duplex-link $n0 $n2 3Mb 1ms DropTail
$ns duplex-link $n1 $n2 3Mb 1ms DropTail
$ns duplex-link $n2 $n3 1.5Mb 100ms DropTail

$ns queue-limit $n2 $n3 10

set udp [new Agent/UDP]
set null [new Agent/Null]
set cbr [new Application/Traffic/CBR]

$ns attach-agent $n0 $udp
$ns attach-agent $n3 $null
$ns connect $udp $null
$cbr attach-agent $udp

set tcp [new Agent/TCP]
set sink [new Agent/TCPSink]
set ftp [new Application/FTP]

$ns attach-agent $n1 $tcp
$ns attach-agent $n3 $sink
$ns connect $tcp $sink
$ftp attach-agent $tcp


$ns at 1.0 "$cbr start"
$ns at 1.5 "$ftp start"
$ns at 3.0 "$ftp stop"
$ns at 3.5 "$cbr stop"
$ns at 4.0 "finish"
$ns run
