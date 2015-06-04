//
//  IDSServiceAuthentication.h
//  Indoors
//
//  Created by Mina Haleem on 16.07.13.
//  Copyright (c) 2013 Indoors. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "IndoorsError.h"

@protocol IDSServiceAuthenticationDelegate
- (void)serviceAuthenticationSuccessForLicenseKey:(NSString*)licenseKey;
- (void)serviceAuthenticationFailForLicenseKey:(NSString*)licenseKey withError:(IndoorsError*)error;
@end

@interface IDSServiceAuthentication : NSObject
- (void)authWithLicenseKey:(NSString*)licenseKey;

@property (nonatomic, strong) id<IDSServiceAuthenticationDelegate> delegate;
@end
