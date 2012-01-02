#!/bin/env python
import sys
import lxml
import urllib
import popen2
import time
import os
from lxml import etree

list_url='http://blog.csdn.net/im3094/?viewmode=contents'

#list_string = urllib.urlopen(list_url).read()
OUTPUT_DIR='csdn_article'
if not os.path.exists(OUTPUT_DIR):
    os.makedirs(OUTPUT_DIR)

html_parser = etree.HTMLParser()
doc = etree.parse(sys.stdin, html_parser)
for div in  doc.xpath('//div[@class="list_item list_view"]'):
    is_original = div.xpath('./div[@class="article_title"]/span/attribute::class')[0].find("ico_type_Original") != -1
    artical_anchor = div.xpath("./descendant::a[starts-with(@href, '/im3094/article')]")[0]
    title = artical_anchor.get("title")
    href = artical_anchor.get("href")
    postdate = div.xpath('./div[@class="article_manage"]/span[@class="link_postdate"]')[0].text

    url="http://blog.csdn.net" + href
    print is_original,title, url, postdate
    sub_process_stdout, sub_process_stderr = popen2.popen2("wget '%s' -q -O - -U 'Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/535.7 (KHTML, like Gecko) Chrome/16.0.912.63 Safari/535.7'" % url)

    detail_doc = etree.parse(sub_process_stdout, html_parser)
    article_content = ''
    for ele in detail_doc.xpath('//div[@id="article_content"]/child::*'):
	article_content += etree.tostring(ele)

    artical_filename = '%s/article.%s' % (OUTPUT_DIR, os.path.basename(href))
    o = open(artical_filename, 'w+')

    print >> o, "url: ", url
    print >> o, ("title: %s" % title).encode('utf8')
    print >> o, ("postdate: %s"% postdate).encode('utf8')
    print >> o, ""
    print >> o, article_content

    time.sleep(10)
    
