//
//  CCObjectToDictionary.h
//  LocalText406
//
//  Created by 孙一越 on 2018/5/18.
//  Copyright © 2018年 孙一越. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 对象转字典的帮助方法
 */
@interface CCObjectToDictionary : NSObject
+ (NSDictionary*)getObjectData:(id)obj;
@end
