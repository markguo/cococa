#!/usr/bin/env python
#
# Copyright 2007 Google Inc.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#
from google.appengine.ext import webapp
from google.appengine.ext.webapp import util


import unittest
from weibopy.auth import OAuthHandler, BasicAuthHandler
from weibopy.api import API

consumer_key= "2367614552"
consumer_secret ="2f3df7f110bfa5a4826c3113073f9594"

class Auth(webapp.RequestHandler):
	def post(self):
		p = self.response.out.write
		p('<html><body>You send:<pre>')
		r = self.request

		request_token = r.get('oauth_token_token')
		request_secret = r.get('oauth_token_secret')
		verifier = r.get('verifier')

		p(request_token)
		p('<br />')
		p(request_secret)
		p('<br />')

		p(verifier)
		p('<br />')
		auth = OAuthHandler(consumer_key, consumer_secret, )
		auth.set_request_token(request_token, request_secret)

		access_token = auth.get_access_token(verifier)
		p('access_token: %s <br/>' % access_token.key)
		p('access_sceret: %s <br/>' % access_token.secret)

class MainHandler(webapp.RequestHandler):

    callback_url = 'http://localhost:8080/'
    def __init__(self):
            """ constructor """

    def getAtt(self, key):
        try:
            return self.obj.__getattribute__(key)
        except Exception, e:
            print e
            return ''

    def getAttValue(self, obj, key):
        try:
            return obj.__getattribute__(key)
        except Exception, e:
            print e
            return ''

    def PINauth(self):
        print 'Please authorize: ' + auth_url
        verifier = raw_input('PIN: ').strip()
        self.auth.get_access_token(verifier)
        self.api = API(self.auth)

    def get(self):
        self.auth = OAuthHandler(consumer_key, consumer_secret, )
        auth_url = self.auth.get_authorization_url()
	oauth_token_secret = self.auth.request_token.secret
	oauth_token_token = self.auth.request_token.key
	self.response.out.write(
			'''<form method="POST" action="/auth" target="_blank">
			<input type="text" name="oauth_token_token" value="%s">request_token</input>
			<input type="text" name="oauth_token_secret" value="%s">request_token_secret</input>
			<input type="text" name="verifier" value=""></input>
			<input type="submit">submit</input>
			</form>
			''' % (oauth_token_token, oauth_token_secret))

        self.response.out.write('<a href="%s" target="_blank">%s</a>' % (auth_url, auth_url))


def main():
    application = webapp.WSGIApplication([('/', MainHandler),
	    ('/auth', Auth)],
                                         debug=True)
    util.run_wsgi_app(application)


if __name__ == '__main__':
    main()
