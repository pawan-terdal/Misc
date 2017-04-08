 #!/bin/bash
 for i in 1 2 3 4 5 6 7 8 9 10
 do
    echo "$i Ans." >> output.txt
    cat p$i.asm >> output.txt
    cat space.txt >> output.txt
 done
