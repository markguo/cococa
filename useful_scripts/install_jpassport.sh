rsync 10.11.203.83::search/JPassport-Client-Apache20-Module-1.2.1-1.x86_64.rpm /search/
cd /search/
rpm -Uvh --relocate /usr/lib64=/usr/local/passport_apache_2x/lib64 JPassport-Client-Apache20-Module-1.2.1-1.x86_64.rpm 
yum install log4cpp apr apr-util  xerces-c  -y
cp /usr/local/passport_apache_2x/lib64/libxml-security-c.so.13.0 /usr/local/passport_apache_2x/lib64/libsaml.so.5.0.1 /usr/lib64/
ln -s /usr/lib64/libsaml.so.5.0.1 /usr/lib64/libsaml.so.5
ln -s /usr/local/passport_apache_2x/conf/jpassport.conf /etc/httpd/conf.d/
