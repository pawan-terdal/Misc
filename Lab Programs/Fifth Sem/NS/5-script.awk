BEGIN {
  packetsReceived = 0;
  throughput = 0.0;
}
{
  if(($1 == "r") && ($5 == "tcp") && ($10 == "4.0")) {
    packetsReceived++;
  }
}
END {
  throughput = (packetsReceived * 8) / (95000.0);
  printf("Packets Received : %d\n", packetsReceived);
  printf("Throughput : %f\n", throughput);
}