//
//  MessageDraft.h
//  CCIMLib
//
//  Created by 孙一越 on 2018/3/23.
//  Copyright © 2018年 孙一越. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface MessageDraft : NSObject
/**
 草稿信息 
 */
@property (nonatomic,strong)NSString *text;
/**
 会话类型，同Session.type
 */
@property (nonatomic,strong)NSNumber *cType;
/**
 会话ID，同Session.id
 */
@property (nonatomic,strong)NSString *sid;

- (instancetype)initWith:(NSNumber *)cType sid:(NSString *)sid text:(NSString *)text;
@end
