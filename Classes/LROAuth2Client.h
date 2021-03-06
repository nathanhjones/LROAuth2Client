//
//  LROAuth2Client.h
//  LROAuth2Client
//
//  Created by Luke Redpath on 14/05/2010.
//  Copyright 2010 LJR Software Limited. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "LROAuth2ClientDelegate.h"
#import "LROAuth2AccessToken.h"

@interface LROAuth2Client : NSObject {
  NSString *clientID;
  NSString *clientSecret;
  NSURL *redirectURL;
  NSURL *cancelURL;
  NSURL *userURL;
  NSURL *tokenURL;
  LROAuth2AccessToken *accessToken;
  NSMutableArray *requests;
  id<LROAuth2ClientDelegate> __unsafe_unretained delegate;
  BOOL debug;
  
 @private
  BOOL isVerifying;
}
@property (nonatomic, copy) NSString *clientID;
@property (nonatomic, copy) NSString *clientSecret;
@property (nonatomic, copy) NSURL *redirectURL;
@property (nonatomic, copy) NSURL *cancelURL;
@property (nonatomic, copy) NSURL *userURL;
@property (nonatomic, copy) NSURL *tokenURL;
@property (nonatomic, copy) NSURL *approvalStepURL; // used to present overlay hiding ugly oauth forms
@property (nonatomic, copy) NSArray *scope; // used to request auth to particular levels of scope
@property (nonatomic, copy) NSString *responseType; // defaults to 'code'
@property (nonatomic, readonly) LROAuth2AccessToken *accessToken;
@property (nonatomic, unsafe_unretained) id<LROAuth2ClientDelegate> delegate;
@property (nonatomic, assign) BOOL debug;

- (id)initWithClientID:(NSString *)_clientID 
                secret:(NSString *)_secret 
           redirectURL:(NSURL *)url;

- (NSURLRequest *)userAuthorizationRequestWithParameters:(NSDictionary *)additionalParameters;
- (void)verifyAuthorizationWithAccessCode:(NSString *)accessCode;
- (void)refreshAccessToken:(LROAuth2AccessToken *)_accessToken;
@end

@interface LROAuth2Client (UIWebViewIntegration) <UIWebViewDelegate>
- (void)authorizeUsingWebView:(UIWebView *)webView;
- (void)authorizeUsingWebView:(UIWebView *)webView additionalParameters:(NSDictionary *)additionalParameters;
- (void)extractAccessCodeFromCallbackURL:(NSURL *)url;
@end
