//
//  CCTextMessage.h
//  CCIMLib
//
//  Created by 孙一越 on 2018/3/28.
//  Copyright © 2018年 孙一越. All rights reserved.
//

#import <CCIMLib/CCIMLib.h>

@interface CCTextMessage : CCMessageContent
/*!
 文本消息的内容
 */
@property(nonatomic, strong) NSString *content;
/*!
 初始化文本消息
 
 @param content 文本消息的内容
 @return        文本消息对象
 */
- (instancetype)initWithContent:(NSString *)content;
@end
