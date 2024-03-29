//
//  Pyze.h
//  Pyze v5.5.4
//
//  Copyright © 2016 Pyze Technologies. All rights reserved.
//

#import <UIKit/UIKit.h>

#import "PyzeEvent.h"

//! Project version number for Pyze.
FOUNDATION_EXPORT double PyzeVersionNumber;

//! Project version string for Pyze.
FOUNDATION_EXPORT const unsigned char PyzeVersionString[];


/**
 *  PyzeLogLevel
 *  Log level of the SDK.
 *  Default is Minimal Logs
 */
typedef NS_ENUM(NSInteger, PyzeLogLevel) {
    /**
     *  Log Minimal
     *
     *  How to use:
     *
     *    [Pyze logThrottling:PyzelogLevelMinimal];
     */
    PyzelogLevelMinimal = 0,
    /**
     *  Log Mininmal + warnings
     *
     *  How to use:
     *
     *    [Pyze logThrottling:PyzelogLevelWarnings];
     */
    PyzelogLevelWarnings = 1,
    /**
     * Log Mininmal + warnings + errors
     *
     * How to use:
     *
     *    [Pyze logThrottling:PyzelogLevelErrors];
     */
    PyzelogLevelErrors = 2,
    /**
     * Log all messages
     *
     * How to use:
     *
     *    [Pyze logThrottling:PyzelogLevelAll];
     */
    PyzelogLevelAll = 3
};

/**
 *  PyzeAspectRatio
 *
 *  It will be used to display InApp Messages screen based on the aspect ratio of the screen on which In App messages will be presented.
 */
typedef NS_ENUM(NSInteger, PyzeAspectRatio) {
    /**
     *  Full size screen. InApp Messages screen will cover the screen on which In App messages will be presented.
     */
    PyzeAspectRatioFullSize,
    /**
     *  3/4 of the screen. InApp Messages screen will cover 75% of the screen on which In App messages will be presented.
     */
    PyzeAspectRatioThreeQuarterSize,
    /**
     *  1/2 of the screen. InApp Messages screen will cover 50% of the screen on which In App messages will be presented.
     */
    PyzeAspectRatioHalfSize
};

/**
 *  PyzeInAppMessageType
 *
 *  This enum will be used to display New InApp messages [Unread messages] or Previous messages [Read messages] or both.
 *
 */
typedef NS_ENUM(NSInteger, PyzeInAppMessageType) {
    /**
     *  New InApp messages [Unread messages including unfetched]
     */
    PyzeInAppTypeUnread,
    /**
     *  Previous messages [Read messages]
     */
    PyzeInAppTypeRead,
    /**
     *  New InApp messages [Unread messages] & Previous messages [Read messages]
     */
    PyzeInAppTypeAll
};


/**
 *  Pyze deep link status enumeration, useful to determine whether deeplink provided, successful or failed.
 *
 *  - Since: 2.3.0
 */
typedef NS_ENUM(NSInteger, PyzeDeepLinkStatus) {

    /**
     *  Pyze call to action provided when user taps on any of the button while creating the in-app
     */
    PyzeCTA = 0,
    /**
     *  Deeplink not provided while creating the in-app
     */
    PyzeDeepLinkNotProvided,
    /**
     *  Deeplink successfully called. For Example: (http://pyze.com or yelp://search?term=burritos where yelp application is installed on the device)
     */
    PyzeDeepLinkCallSuccessful,
    /**
     *  Invalid or deeplink not found. For Example: (mispelt htp://pyze.com or yelp://search?term=burritos where yelp application is not installed on the device)
     */
    PyzeDeepLinkCallFailed,
    /**
     *  Unique identifier for button click provided while creating the in-app. This needs to be handled by apps.
     */
    PyzeUniqueIdentifier,
    /**
     *  Web-hook provided while creating in-app message.
     */
    PyzeWebhook,

};


#pragma mark - Pyze

/**
 * Pyze main class
 *
 * This is the main class for the Pyze iOS SDK. Use method initializeWithKey: to initialize the Library.
 * For troubleshooting during development and in debug mode, you can throttle the logging level using method
 * debugLogThrottling:
 * In the release mode or deployment the SDK will log minimally.
 *
 * Please visit [Pyze Developer Center](http://docs.pyze.com) for more information.
 *
 * You will need an app-specific key "Pyze App Key" from: [growth.pyze.com](https://growth.pyze.com/)
 *
 */
@interface Pyze : NSObject


/// @name Initializing Pyze

/**
 *  Initializes the Pyze library. Call this method in the app delegate's method
 *  application:willFinishLaunchingWithOptions. [Get Pyze App Key from growth.pyze.com](http://pyze.com/get-Pyze-App-Key.html)
 *
 *  Usage:
 *
 *      [Pyze initialize:@"Pyze App Key obtained from growth.pyze.com"];
 *
 *  @param pyzeAppKey The app-specific key obtained from [growth.pyze.com](http://pyze.com/get-Pyze-App-Key.html)
 *  @warning *Important:* Get an app-specific key from [growth.pyze.com](http://pyze.com/get-Pyze-App-Key.html)
 *
 *  - Since: 2.0.5
 *
 */
+ (void) initialize:(NSString *) pyzeAppKey;

/**
*  Initializes the Pyze library. Call this method in the app delegate's method
*  application:willFinishLaunchingWithOptions. [Get Pyze App Key from growth.pyze.com](http://pyze.com/get-Pyze-App-Key.html)
*  Include the 'Pyze App Key' in application's Info.plist with key name 'PYZE_APP_KEY'
*
*  Usage:
*
*     [Pyze initialize: PyzelogLevelMinimal];
*
*  @param logLevel Log level you would wish to see in the console.
*  @warning *Important:* Get an app-specific key from [growth.pyze.com](http://pyze.com/get-Pyze-App-Key.html) asn save in info
*
*  - Since: 2.0.5
*
*/
+ (void) initializeWithLogLevel:(PyzeLogLevel) logLevel;

/**
 *  Initializes the Pyze library and specify the log throttling level. Call this method in the app delegate's method
 *  application:willFinishLaunchingWithOptions. [Get Pyze App Key from growth.pyze.com](http://pyze.com/get-Pyze-App-Key.html)
 *
 *  Usage:
 *
 *      [Pyze initialize:@"Pyze App Key obtained from growth.pyze.com"   withLogThrottling: PyzelogLevelAll];
 *
 *  @param pyzeAppKey The app-specific key obtained from [growth.pyze.com](http://pyze.com/get-Pyze-App-Key.html)
 *  @param logLevel Log level you would wish to see in the console.
 *  @warning *Important:* Get an app-specific key from [growth.pyze.com](http://pyze.com/get-Pyze-App-Key.html)
 *
 *  - Since: 2.3.3 (added for consistency with Android and Unity agents)
 *
 */
+ (void) initialize:(NSString *)pyzeAppKey withLogThrottling: (PyzeLogLevel) logLevel;


/**
 *  Log throttling level can be changed anytime in the app
 *
 *  How to use:
 *
 *    [Pyze logThrottling:PyzelogLevelMinimal];
 *
 *  or
 *
 *    [Pyze logThrottling:PyzelogLevelErrors];
 *
 *  @param logLevel Log level you would wish to see in the console.
 *
 *  - Since: 2.0.5
 *
 */
+(void) logThrottling:(PyzeLogLevel) logLevel;

/// @name  Opt out data collection

/**
 *  Will stop collecting all data
 *
 *  @param shouldOptout Boolean value to decide if data tracking should be stopped.
 *
 - Since: 5.0.2
 */
+ (void) setUserOptOut:(BOOL)shouldOptout;

/**
 *  Will stop collecting all data and delete existing data from the server
 *
 *  @param shouldDelete Boolean value to decide if data collection should be stopped and delete existing data from the server
 *
 - Since: 5.0.2
 */
+ (void) deleteUser:(BOOL)shouldDelete;

/// @name  Create Timer Reference to use in Timed Custom Events using PyzeCustomEvent class

/**
 *  Pyze Timer Reference is a time interval since a Pyze internal reference time in seconds with millisecond precision e.g. 6.789 seconds (or 6789 milliseconds)
 *
 *  It is used to time tasks and report in events.
 *
 *  usage:
 *
 *     //Start timing
 *     double referenceFileUploadStart = [Pyze timerReference];
 *     ...
 *     ...
 *     //time and send elapsedSeconds
 *     [PyzeCustomEvent postWithEventName:@“File Uploaded”
 *                     withTimerReference:referenceFileUploadStart];
 *
 */
+(double) timerReference;


/**
 *  Returns the Pyze instance identifier. If Pyze not initialized, returns an empty string.
 *
 *  @return Pyze Instance identifier
 */
+ (NSString *) getPyzeAppInstanceId;



/// @name Push notification helper APIs


/**
 *  Use this API to set the push notification device token. This will trigger Pyze to update the device token, which internally would be used to send the push notification. Call this API in Application's AppDelegate method application:didRegisterForRemoteNotificationsWithDeviceToken:.
 *
 *
 *  @param deviceToken device Token bytes received from the AppDelegate's method call.
 
 *  - Since: 2.2.1
 */
+(void) setRemoteNotificationDeviceToken:(NSData *) deviceToken;


/**
 *  Use this API to set the push notification device token. This will trigger Pyze to update the device token, which internally would be used to send the push notification. Call this API in Application's AppDelegate method application:didRegisterForRemoteNotificationsWithDeviceToken:.
 *  The method accepts the token as NSStirng.
 *
 *  @param deviceToken device Token bytes received from the AppDelegate's method call.
 
 *  - Since: 5.0.1
 */
+(void) setRemoteNotificationDeviceTokenString:(NSString *) deviceToken;


/**
 *  Use this API to process the push/remote notification. Call this everytime when you receive the remote notification from application:didReceiveRemoteNotification or application:didReceiveRemoteNotification:fetchCompletionHandler:. 
    
     If you are using interactive push notifications e.g. Button handlers in push messages, then use processReceivedRemoteNotificationWithId:
    instead.
 
 *  @param userInfo User information received as a payload.
 
 *  - Since: 2.2.1
 */
+(void) processReceivedRemoteNotification:(NSDictionary *) userInfo;
+(void) processReceivedRemoteNotification:(NSDictionary *) userInfo withState: (UIApplicationState) state withCompletionHandler: (void (^)(UIBackgroundFetchResult)) handler;

/**
 *  Use this API to process the local/remote push notifications. Call this everytime when you receive the remote notification from application:handleActionWithIdentifier:forRemoteNotification:completionHandler:. For example: Button handlers in
     interactive push notifications. If you are not using button handlers in push messages, you can pass nil to 'identifer' parameter.

 *  @param userInfo User information received as a payload.
 *
 *  - Since: 2.9.1
 */

+(void) sendPushFeedback:(NSString *) identifer withUserInfo:(NSDictionary *) userInfo;


/// @name In-App Notifications (using Built-in User Interface)

/**
 *  This will add a badge to the UIControl (e.g.: UIButton) depicting the number of unfetched and new in-app messages available.
 *
 *  @param control UIControl to add badge to.
 
 - Since: 2.3.2
 
 */
+(void) addBadge:(UIControl *) control;

+(void) sendCampaignFeedbackWithMsgType:(NSString *) msgType messageId:(NSString *) mid campaignId:(NSString *) cid nodeId:(NSString *) nodeId action:(NSString *) action userAction:(NSDictionary *) userAction;




/**
 *  Hash function can be used to convert any NSString to an hashed equivalent.
 *  The generated string is suffixed with two hash characters ##
 *  This function is useful to avoid collecting any information that may be private or sensitive.
 *
 *  @param stringToHash         String to Hash
 *
 *  - Since: 2.7.0
 */
+ (NSString *)hash:(NSString *)stringToHash;


/// @name Deprecated methods (to be removed in subsequent releases)

/**
 *  Deprecated in favor of static initialize: method
 *
 *  @see +initialize:
 *
 */
- (void) initializeWithKey:(NSString *) pyzeAppKey;

/**
 *  Deprecated in favor of static method logThrottling:
 *
 *  @see +logThrottling:
 *
 */
-(void) logThrottling:(PyzeLogLevel) logLevel;

/**
 *  Get the shared instance of Pyze API
 *
 *  @return Pyze instance type.
 */
+ (Pyze*) sharedPyze;




/**
 *  init method is unavailable. Use initializeWithKey: method instead.
 *
 *  @see initializeWithKey:
 *
 *  @return instance type
 */
-(instancetype) init NS_UNAVAILABLE;

+(void) showInAppNotification;

@end




#pragma mark - Pyze Personalization Intelligence

/**
 *  PyzePersonalizationIntelligence
 *  See: http://pyze.com/iOS-Personalization.html and http://pyze.com/product/personalization-intelligence.html for more details.
 *
 *  This class provides access to get the personalization intelligence tags. These tags are set in the intelligence explorer.
 *
 *  - Since: 2.6.0
 */

@interface PyzePersonalizationIntelligence : NSObject

/**
 *  Get all tags assigned to the user.  Note: Tags are case sensitive, "High Value" and "high value" are different tags.
 *
 *    [PyzePersonalizationIntelligence getTags:^(NSArray *tagsList) {
 *         NSLog(@"PyzePersonalizationIntelligence tags = %@", tagsList);
 *    }];
 *
 *  @param completionHandler Handler with array of tag strings or nil.
 */
+(void) getTags:(void (^) (NSArray * tagsList)) completionHandler;


/**
 *  Returns true if requested tag is assigned to user.   Note: Tags are case sensitive, "High Value" and "high value" are different tags
 *
 *      NSLog(@"isTagSet = %d", [PyzePersonalizationIntelligence isTagSet:@"loyal"]);
 *
 *  @param tag The selected tag.
 *
 *  @return Returns YES if found.
 */
+(BOOL) isTagSet:(NSString *) tag;

/**
 *  Returns true if at least one tag is assigned.    Note: Tags are case sensitive, "High Value" and "high value" are different tags.
 *
 *      NSLog(@"areAnyTagsSet = %d",[PyzePersonalizationIntelligence areAnyTagsSet:@[@"High value"]]);
 *
 *  @param tagsList The array tag list strings.
 *
 *  @return Returns YES if any of the tags is found.
 */
+(BOOL) areAnyTagsSet:(NSArray *) tagsList;


/**
 *  Returns true if all tags specified are assigned to user.   Note: Tags are case sensitive, "High Value" and "high value" are different tags.
 *
 *     NSLog(@"areAllTagsSet = %d", [PyzePersonalizationIntelligence areAllTagsSet:@[@"loyal", @"whale",@"High value"]]);
 *
 *  @param tagsList The array tag list strings.
 *
 *  @return Returns YES if all of the tags are found.
 */
+(BOOL) areAllTagsSet:(NSArray *) tagsList;

@end


/**
 *  PyzeAttribution
 *  This class contains methods to post the attribution data to Pyze from attribution partners
 */
@interface PyzeAttribution : NSObject

/**
 *  Send Appsflyer attribution data to pyze.
 *
 *     -(void)onConversionDataReceived:(NSDictionary*) installData {
 *          [PyzeAttribution postAppsFlyerAttribution:installData];
 *      }
 *
 *  @param attributionData attribution/install data obtained from Appsflyer
 *
 *  - Since: 3.6.0
 */
+ (void) postAppsFlyerAttribution:(NSDictionary *)attributionData;

@end

#pragma mark - Pyze Notification

/**
 *  PyzeNotificationActionType
 *  Type of actions available for Notification
 *
 *  - Since: 3.7.0
 */
typedef NS_ENUM(NSInteger, PyzeNotificationActionType) {
    /**
     *  Dismisses the notificatoin.
     */
    ePyzeNotificationActionTypeNone = 0,
    /**
     *  Opens home page of the app.
     */
    ePyzeNotificationActionTypeHome = 1,
    /**
     *  Opens a deeplink URL.
     */
    ePyzeNotificationActionTypeDeepLink = 2,
    /**
     *  Opens URL in Safari.
     */
    ePyzeNotificationActionTypeWebLink = 3,
    /**
     *  Opens share activity dialog.
     */
    ePyzeNotificationActionTypeShare = 4
};


/**
 *  PyzeNotificationAction
 *  This class contains informations related to the Pyze interactive notification action.
 *
 *  - Since: 3.7.0
 */
@interface PyzeNotificationAction : NSObject

/**
 *  Name of the notification action.
 */
@property (strong, nonatomic) NSString *buttonName;
/**
 *  Type of the notification action in readable string format
 */
@property (assign, nonatomic) NSString *buttonActionTypeString;
/**
 *  Type of the notification action.
 */
@property (assign, nonatomic) PyzeNotificationActionType buttonActionType;
/**
 *  Deep link url if the, available action type is 'ePyzeNotificationActionTypeDeepLink'
 */
@property (strong, nonatomic) NSURL *deepLinkURL;
/**
 *  Content text to share, available if the action type is 'ePyzeNotificationActionTypeShare'
 */
@property (strong, nonatomic) NSString *shareText;
/**
 *  Web page url, available if the action type is 'ePyzeNotificationActionTypeSafari'
 */
@property (strong, nonatomic) NSURL *webPageURL;
/**
 * Action identifier
 */
@property (strong, nonatomic) NSString *buttonActionIdentifier;

@end

/**
 *  PyzeNotificationContent
 *  This class contains information parsed from the push notification payload.
 *
 *  - Since: 3.7.0
 */
@interface PyzeNotificationContent : NSObject


/**
 *  Title of the notification
 */
@property (strong, nonatomic) NSString *title;
/**
 *  SubTitle of the notification
 */
@property (strong, nonatomic) NSString *subTitle;
/**
 *  Notification content text
 */
@property (strong, nonatomic) NSString *body;
/**
 *  Notificatoin category identifier
 */
@property (strong, nonatomic) NSString *categoryIdentifier;
/**
 *  Media attachment url, if its a rich push notification and 'nil' otherwise
 */
@property (strong, nonatomic) NSString *mediaURL;
/**
 *  Type/extension of notification attachment
 */
@property (strong, nonatomic) NSString *mediaType;
/**
 *  Array of all notification actions consisting of 'PyzeNotificationAction' objects
 */
@property (strong, nonatomic) NSMutableArray *allActions;
/**
 *  User selected notification action. selected action with buttonName 'com.apple.UNNotificationDefaultActionIdentifier' indicates the default notification tap.
 */
@property (strong, nonatomic) PyzeNotificationAction *selectedAction;

@end





/**
 *  PyzeNotification
 *  Use this class to define Pyze default notification categories, push payload and handle default notification actions provided by Pyze (Ex. Share/Deep link/Web page url).
 *
 *  - Since: 3.7.0
 */
@interface PyzeNotification : NSObject

/**
 *  Use this to pass as 'actionIdentifier' in order to handle the default notification tap.
 */
#define k_PyzeDefaultNotificationAction  @"com.apple.UNNotificationDefaultActionIdentifier"


/**
 *  Use this API to get the list of Pyze default notification categories available.
 *
 *  @return NSSet containing Push categories
 
 *  - Since: 3.7.0
 */
+ (NSSet *) getPyzeDefaultNotificationCategories;

+(void)initWithLaunchOptions:(NSDictionary *)launchOptions;

/**
 *  This will perform the selected notification action as identified by 'actionIdentifier'
 *
 *  @param userInfo User info dictionary obtained from the notification receive callback method in AppDelegate
 *  @param actionIdentifier Identifier of user opted action.
 *
 */
+ (void) handlePushNotificationResponseWithUserinfo:(NSDictionary *)userInfo actionIdentifier:(NSString *)actionIdentifier;


/**
 *  Use this API to parse the push notification response.
 *
 *  @param userInfo User information received as a payload
 *  @param completionHandler Completion handler, with 'PyzeNotificationContent' as parameter
 *
 */
+ (void) parsePushNotificationResponseWithUserinfo:(NSDictionary *)userInfo completionHandler:(void (^)(PyzeNotificationContent *pyzePushObject))completionHandler;


/**
 *  Use this API to parse the push notification response.
 *  In addition to 'parsePushNotificationResponseWithUserinfo:completionHandler:', this method will provide 'PyzeNotificationContent.selectedAction' which is the user opted action and respective details.
 *
 *  @param userInfo User information received as a payload
 *  @param actionIdentifier Identifier of user opted action.
 *  @param completionHandler Completion handler, with 'PyzeNotificationContent' as parameter
 *
 */
+ (void) parsePushNotificationResponseWithUserinfo:(NSDictionary *)userInfo actionIdentifier:(NSString *)actionIdentifier completionHandler:(void (^)(PyzeNotificationContent *pyzePushObject))completionHandler;


@end
