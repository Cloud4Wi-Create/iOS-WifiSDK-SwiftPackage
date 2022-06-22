//
//  Customer.h
//  Cloud4WiSDKWiFi
//

#ifndef Customer_h
#define Customer_h

#import "CustomerDocument.h"

@interface Customer : NSObject

@property NSString *username;
@property NSString *password;
@property NSString *firstName;
@property NSString *lastName;
@property NSString *phoneNumber;
@property NSString *email;
@property NSString *gender;
@property NSString *birthDate;
@property NSString *language;
@property NSString *country;
@property NSString *zipCode;
@property NSString *companyName;
@property NSString *civilStatus;
@property BOOL phoneVerified;
@property BOOL emailVerified;
@property NSNumber *ppd;
@property NSNumber *profiling;
@property NSDictionary *custom;
@property NSDictionary *policies;
@property CustomerDocument *document;
@property BOOL lock;
@property NSString *extId;
@property NSString *extProp1;
@property NSString *extProp2;

- (instancetype) init;

@end

#endif /* Customer_h */
