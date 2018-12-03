//
//  CCSession.h
//  CCIMLib
//
//  Created by 孙一越 on 2018/3/21.
//  Copyright © 2018年 孙一越. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Session.h"
@interface CCSession : NSObject
/**
 会话Id
 */
@property (nonatomic,strong)NSString *id;
/**
 会话类型
 1    单人会话
 3    讨论组会话
 11    公众号
 */
@property (nonatomic,strong)NSNumber *type;
/**
 已读消息ID
 */
@property (nonatomic,strong)NSNumber *readMsgId;
/**
 会话变更时间戳
 */
@property (nonatomic,strong)NSNumber *timestamp;
/**
 未读消息数量
 */
@property (nonatomic,strong)NSNumber *cnt;
/**
 草稿内容
 */
@property (nonatomic, strong) NSString* draft;

/**
 该会话中最新的一条消息的messageId
 */
@property(nonatomic, strong) NSString *messageId;


- (instancetype)initWith:(Session *)session;
@end
