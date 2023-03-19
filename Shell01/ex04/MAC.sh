ifconfig | sed -n '/ether /p' | cut -d ' ' -f 2
