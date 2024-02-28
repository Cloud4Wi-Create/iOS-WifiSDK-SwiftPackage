//
//  HttpRequest.h
//  Cloud4WiSDKWiFi
//

#ifndef HttpRequest_h
#define HttpRequest_h

#import <Foundation/Foundation.h>

@interface HttpRequest: NSObject

+(void)setShowAPIDebug: (BOOL) _showAPIDebug;

-(instancetype)withHeaders:(NSDictionary *) headers;

-(instancetype)get:(NSString *)url;

-(instancetype)post:(NSString *)url body:(NSObject *) body;

-(instancetype)put:(NSString *)url body:(NSObject *) body;

-(NSString*) exec:(NSError**) error;

@end

#endif /* HttpRequest_h */
