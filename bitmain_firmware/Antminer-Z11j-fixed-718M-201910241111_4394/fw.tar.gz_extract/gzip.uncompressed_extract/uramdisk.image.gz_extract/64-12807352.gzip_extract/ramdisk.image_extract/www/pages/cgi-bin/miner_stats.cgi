cgminer-api -o {\"command\":\"stats\"} | sed 's/}{/},{/g' > /tmp/1.cgi
cat /tmp/1.cgi
