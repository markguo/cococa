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
RSS_TEMPLETE_BEGIN='''
<?xml version="1.0" encoding="utf-8" ?>
<?xml-stylesheet type="text/xsl" title="XSL Formatting" href="/rss.xsl" media="all" ?>
<rss version="2.0">
<channel>
    <title>xx</title>
    <image>
    <link>http://blog.csdn.net</link>
    <url>http://static.blog.csdn.net/images/logo.gif</url>
    </image>
    <description>yy</description>
	<link>http://blog.csdn.net/im3094</link>
	<language>zh-cn</language>
	<generator>http://blog.csdn.net</generator>
	<ttl>5</ttl>
	<copyright>
		<![CDATA[Copyright &copy; IM3094]]>
	</copyright> 
	<pubDate>2012-1-2 21:26:11</pubDate>
	'''
RSS_TEMPLETE_END = '''
</channel>
</rss>
'''

RSS_ITEM_TEMPLETE='<item> <title>__TITLE__</title> <link>__URL__</link> <guid>__URL__</guid> <author>IM3094</author> <pubDate>__POST_DATE__</pubDate> <description>__CONTENT__</description> <category></category> </item>'
    
print RSS_TEMPLETE_BEGIN
for div in  doc.xpath('//div[@class="list_item list_view"]'):
    is_original = div.xpath('./div[@class="article_title"]/span/attribute::class')[0].find("ico_type_Original") != -1
    artical_anchor = div.xpath("./descendant::a[starts-with(@href, '/im3094/article')]")[0]
    title = artical_anchor.get("title")
    href = artical_anchor.get("href")
    postdate = div.xpath('./div[@class="article_manage"]/span[@class="link_postdate"]')[0].text

    url="http://blog.csdn.net" + href
    print >> sys.stderr, is_original,title, url, postdate
    sub_process_stdout, sub_process_stderr = popen2.popen2("wget '%s' -q -O - -U 'Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/535.7 (KHTML, like Gecko) Chrome/16.0.912.63 Safari/535.7'" % url)

    detail_doc = etree.parse(sub_process_stdout, html_parser)
    article_content = ''
    for ele in detail_doc.xpath('//div[@id="article_content"]/child::*'):
	article_content += etree.tostring(ele)

    item = '''<item>
    <title>%s</title>
    <link>%s</link>
    <guid>%s</guid>
    <author>benguo</author>
    <pubDate>%s</pubDate>
    <description>%s</description>
    <category></category>
</item>'''%( title, url, url, postdate, article_content)
    #artical_filename = '%s/article.%s' % (OUTPUT_DIR, os.path.basename(href))
    #o = open(artical_filename, 'w+')

    #print >> o, "url: ", url
    #print >> o, ("title: %s" % title).encode('utf8')
    #print >> o, ("postdate: %s"% postdate).encode('utf8')
    #print >> o, ""
    #print >> o, article_content
    print item.encode('utf8')
    time.sleep(3)
    
print RSS_TEMPLETE_END
