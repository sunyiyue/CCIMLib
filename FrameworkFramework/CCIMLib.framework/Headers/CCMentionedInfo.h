//
//  CCMentionedInfo.h
//  CCIMLib
//
//  Created by 孙一越 on 2018/5/17.
//  Copyright © 2018年 孙一越. All rights reserved.
//

#import <Foundation/Foundation.h>
/*!
 @提醒的类型
 */
typedef NS_ENUM(NSUInteger, CCMentionedType) {
    /*!
     @所有人
     */
    CC_Mentioned_All = 1,
    
    /*!
     @部分指定用户
     */
    CC_Mentioned_Users = 2,
};
@interface CCMentionedInfo : NSObject
/*!
 @提醒的类型
 */
@property(nonatomic, assign) CCMentionedType type;

/*!
 @的用户ID列表
 
 @discussion 如果type是@所有人，则可以传nil
 */
@property(nonatomic, strong) NSArray *userIdList;
/*!
 初始化@提醒信息
 
 @param type       @提醒的类型
 @param userIdList @的用户ID列表
 
 @return @提醒信息的对象
 */
- (instancetype)initWithMentionedType:(CCMentionedType)type
                           userIdList:(NSArray *)userIdList;
@end
