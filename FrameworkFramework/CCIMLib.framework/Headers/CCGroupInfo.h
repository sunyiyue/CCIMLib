//
//  CCGroupInfo.h
//  CCIMLib
//
//  Created by 孙一越 on 2018/4/8.
//  Copyright © 2018年 孙一越. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface CCGroupInfo : NSObject

/**
 讨论组ID
 */
@property (nonatomic,strong)NSString *groupId;

/**
 讨论组成员列表
 */
@property (nonatomic,strong)NSArray *memberArray;

/**
 是否免打扰 YES：免打扰
 */
@property (nonatomic,assign)BOOL muted;
@end
