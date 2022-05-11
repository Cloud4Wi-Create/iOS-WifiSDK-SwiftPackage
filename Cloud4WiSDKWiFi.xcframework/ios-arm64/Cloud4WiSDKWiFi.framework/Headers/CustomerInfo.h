//
//  CustomerInfo.h
//  Cloud4WiSDKWiFi
//

#ifndef CustomerInfo_h
#define CustomerInfo_h

@interface CustomerInfo : NSObject

@property NSString*  status;
@property NSString*  generated;
@property BOOL       present;
@property NSString*  id;
@property NSString*  extId;

- (instancetype) initWithJSONString: (NSString *) jsonString
                              error: (NSError **) error;

@end

#endif /* CustomerInfo_h */
