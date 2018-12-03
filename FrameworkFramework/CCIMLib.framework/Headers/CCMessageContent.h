//
//  CCMessageContent.h
//  CCIMLib
//
//  Created by 孙一越 on 2018/3/28.
//  Copyright © 2018年 孙一越. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CCMentionedInfo.h"
/*!
 消息内容的编解码协议
 
 @discussion 用于标示消息内容的类型，进行消息的编码和解码。
 所有自定义消息必须实现此协议，否则将无法正常传输和使用。
 */
@protocol CCMessageCoding <NSObject>
@required

/*!
 将消息内容序列化，编码成为可传输的json数据
 
 @discussion
 消息内容通过此方法，将消息中的所有数据，编码成为json数据，返回的json数据将用于网络传输。
 */
- (NSString *)encode;

/*!
 将json数据的内容反序列化，解码生成可用的消息内容
 
 @param string    消息中的原始json字符串
 
 @discussion
 网络传输的json数据，会通过此方法解码，获取消息内容中的所有数据，生成有效的消息内容。
 */
- (void)decodeWithString:(NSString *)string;

/*!
 返回消息的类型名
 
 @return 消息的类型名
 
 @discussion 您定义的消息类型名，需要在各个平台上保持一致，以保证消息互通。
 
 */
+ (NSString *)getObjectName;

@end

@interface CCMessageContent : NSObject<CCMessageCoding>
/*!
 消息中的@提醒信息
 */
@property(nonatomic, strong) CCMentionedInfo *mentionedInfo;

/**
 时间戳
 */
@property(nonatomic, strong)NSNumber *fakeTimestamp;
@end
