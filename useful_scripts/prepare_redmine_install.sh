#!/bin/bash

if [ $# != 1 ]; then
	echo "usage: $0 <redmine-package-path>"
	exit 1
fi

function die()
{
	echo $@
	exit 1
}
REDMINE_PATH=$1
case $REDMINE_PATH in
*.tar.gz ) ;;
*) echo $REDMINE_PATH must be *.tar.gz; exit1;;
esac

# Install dependences
yum install -y ruby ImageMagick-devel.x86_64 postgresql-devel.x86_64 mysql-devel ruby-devel sqlite-devel.x86_64 

echo Install activerecord v3.2.8
#gem install activerecord -v '3.2.8'

echo
echo Install bundler
#gem install bundler

REDMINE_PACKAGE_NAME=`basename $REDMINE_PATH`
extracted_dir=${REDMINE_PACKAGE_NAME%%.tar.gz}
tar -zvxf $REDMINE_PATH || die "tar -zvxf $REDMINE_PATH failed"
cd $extracted_dir || die "Cannot ce into $extracted_dir"
bundle install --without development 'test' sqlite postgresql || die "bundle install failed"

echo "Prepare env for redmine succeed, see http://www.redmine.org/projects/redmine/wiki/RedmineUpgrade for further instructs if you are upgrading from old version"



