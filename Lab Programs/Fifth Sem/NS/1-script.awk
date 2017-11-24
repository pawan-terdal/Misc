BEGIN {
  nCBR = 0;
  nTCP = 0;
}
{
  if(($1 == "d") && ($5 == "cbr")) {
    nCBR += 1
  }
  if(($1 == "d") && ($5 == "tcp")) {
    nTCP += 1
  }
}
END {
  printf "No of CBR packets droppped %d\n", nCBR;
  printf "No of TCP packets droppped %d\n", nTCP;
}