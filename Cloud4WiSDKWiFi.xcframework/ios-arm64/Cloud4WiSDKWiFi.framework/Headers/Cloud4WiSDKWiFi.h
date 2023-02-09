//
//  Cloud4WiSDKWiFi.h
//  Cloud4WiSDKWiFi
//

#import <Foundation/Foundation.h>
#import "Customer.h"
#import "CustomerCreateResponse.h"
#import "CustomerInfo.h"
#import "CustomerQuery.h"
#import "PasspointProfile.h"
#import "WPA2EnterpriseProfile.h"

//! Project version number for Cloud4WiSDKWiFi.
FOUNDATION_EXPORT double Cloud4WiSDKWiFiVersionNumber;

//! Project version string for Cloud4WiSDKWiFi.
FOUNDATION_EXPORT const unsigned char Cloud4WiSDKWiFiVersionString[];


@interface Cloud4WiSDKWiFi : NSObject

/**
 * This method assumed to be called every time the app is started.
 * This method will (if the customer is already registered/logged in the app)
 *  - update the `lastseen` of the customer
 *  - update the push token of the customer (Firebase token)
 *  - update the guId (GeoUniq device id) of the customer
 *
 *  @param pushToken - push token passed from mobile app
 */
- (void) initC4w: (NSString*) pushToken;

/**
 * Add or update WPA2-Enterprise Wi-Fi profile
 *
 * @param username - authorization user name
 * @param password - authorization password
 * @param onSuccess -  invoked if profile successfully installed
 * @param onError -  invoked if profile installation fails
 *
 */
- (void) createWPA2EnterpriseProfile: (NSString*) username
                           password: (NSString*) password
                          onSuccess: (void (^)(void)) onSuccess
                            onError: (void (^)(NSError *error)) onError;

/**
 * Add or update Passpoint Wi-Fi profile
 *
 * @param username - authorization user name
 * @param password - authorization password
 * @param onSuccess -  invoked if profile successfully installed
 * @param onError -  invoked if profile installation fails
 *
 */
- (void) createPasspointProfile: (NSString*) username
                       password: (NSString*) password
                      onSuccess: (void (^)(void)) onSuccess
                        onError: (void (^)(NSError *error)) onError;

/**
 * Create customer in the Volare platform (Guest User)
 *
 * @param customer - user (Guest User) you want to create
 * @param deduplicateAttribute - deduplicate new customer based on this param.
 * @param onSuccess - invoked if customer successfully created
 * @param onError - invoked if exception occurred
 *
 */
- (void) createCustomer: (Customer*) customer
            deduplicate: (NSString *) deduplicateAttribute
              onSuccess: (void (^)(CustomerCreateResponse *resp)) onSuccess
                onError: (void (^)(NSError *error)) onError;

/**
 * Update existing customer.
 *
 * @param customer - Customer with all fields that needs to be updated. All customer fields except 'username' and 'password' can be updated with this method.
 * @param onSuccess - invoked if customer successfully updated
 * @param onError - invoked if exception occurred
 *
 */
- (void) updateCustomer: (Customer*) customer
              onSuccess: (void (^)(BOOL)) onSuccess
                onError: (void (^)(NSError *error)) onError NS_SWIFT_NAME( updateCustomer(_:onSuccess:onError:) );

/**
 * Get customer info from API by providing login/password credentials
 *
 * @param username - customer login
 * @param password - customer password
 * @param onSuccess - invoked if customer with provided credentials was not found
 * @param onError - invoked if exception occurred
 *
 */
- (void) getCustomerInfo: (NSString*) username
                password: (NSString*) password
               onSuccess: (void (^)(CustomerInfo *resp)) onSuccess
                 onError: (void (^)(NSError *error)) onError;

/**
 * Update API with customer metadata
 *
 * @param onSuccess - invoked if customer info update was proceeded without exceptions
 * @param onError - invoked if exception occurred
 *
 */
- (void) updateCustomerInfo: (void (^)(void)) onSuccess
                    onError: (void (^)(NSError *error)) onError;

/**
 * Create empty customer with default policies.
 *
 * @param onSuccess - invoked if customer was created sucessfully
 * @param onError - invoked if exception occurred
 *
 */
- (void) setupCustomer: (void (^)(CustomerCreateResponse *resp)) onSuccess
               onError: (void (^)(NSError *error)) onError;

/**
 * Check if customer with provided via CustomerQuery properties already exists
 *
 * @param query - <CustomerQuery> object with at least one field initialized
 * @param onSuccess - invoked if `customer exists` call was proceeded without exceptions
 * @param onError - invoked if exception occurred
 */
- (void) checkIfCustomerExists: (CustomerQuery *) query
                     onSuccess: (void (^)(BOOL)) onSuccess
                       onError: (void (^)(NSError *error)) onError;

/**
 * Get list of configured policies over API
 *
 * @param onSuccess - invoked if policies list was successfully obtained
 * @param onError - invoked if exception occurred
 *
 */
- (void) getListOfPolicies: (void (^)(NSArray<NSString *> *policies)) onSuccess
                   onError: (void (^)(NSError *error)) onError;

/**
 * Set client API authentication parameters
 *
 * @param _clientKey - API client key
 * @param _clientSecret - API client secret
 * @param error -  set to non-nil if failed
 */
- (void) setAPIAuthParams: (NSString*) _clientKey
             clientSecret: (NSString*) _clientSecret
                    error: (NSError**) error;

/**
 * Returns list of created WPA2EnterpriseProfiles
 */
- (NSArray<WPA2EnterpriseProfile *> *) getCreatedWPA2EnterpriseProfiles;

/**
 * Returns list of created PasspointProfiles
 */
- (NSArray<PasspointProfile *> *) getCreatedPasspointProfiles;

/**
 * Deletes installed Passpoint profile
 */
- (void) deletePasspointProfile;

/**
 * Deletes installed WPA2Enterprise profile
 */
- (void) deleteWPA2EnterpriseProfile;

/**
 * Configure list of application to be interlinked with current
 *
 * @param identifiers - list of applications identifiers
 */
- (void) setInterlinkedC4WIMobileSDKApplications: (NSArray<NSString *> *) identifiers;

/**
 * Get list of application identifier current interlinked with
 */
- (NSArray<NSString *> *) getInterlinkedC4WIMobileSDKApplications;

/**
 * Removes the customerId saved during the create customer
 * Removes any reference to the customer
 * Removes Wi-Fi profiles related to the customer
 */
- (void) logout;

/**
 * Returns Customer ID
 * @return String `customerId` of the user registered in the app
 * @nullable if no Customer logged in or not registered yet
 */
- (NSString *) getCustomerId;

@end
