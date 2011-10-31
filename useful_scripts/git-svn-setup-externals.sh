#!/bin/bash

# Repository Root: http://svn.sogou-inc.com/svn/websearch4
svn_repo_root=`git svn info|fgrep 'Repository Root:'|awk '{print $3}'`

function checkout_svn()
{
    svn_repo_root=$1
    external_path=${2##^}
    checkout_to=$3
    svn co "${svn_repo_root}${external_path}" $checkout_to
}

git svn propget svn:externals | while read external_path local_path
do
    case $external_path in
	^*) checkout_svn $svn_repo_root $external_path $local_path ;;
	'') continue ;;
	*) echo "UNKNOW external format $external_path" ;;
    esac
done

if [ $? != 0 ]; then
    exit $?
fi

#^/kernel/spider_kernel/tags/web.spider_kernel.20110418.a third-party/spider_kernel
#^/web/web_spider/tags/web.web_spider.20110418.a third-party/web_spider
#^/web/web_selector/tags/web.web_selector.20110407.a third-party/web_selector
