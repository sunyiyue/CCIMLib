//
//  CCAppEngine.h
//  CCIMLib
//
//  Created by 孙一越 on 2018/4/25.
//  Copyright © 2018年 孙一越. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#ifdef NSFoundationVersionNumber_iOS_9_x_Max
#import <UserNotifications/UserNotifications.h>
#endif
@interface CCAppEngine : NSObject<UIApplicationDelegate,UNUserNotificationCenterDelegate>
+ (instancetype)shareEngine;
@end
