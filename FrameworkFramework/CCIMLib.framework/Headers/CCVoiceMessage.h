//
//  CCVoiceMessage.h
//  CCIMLib
//
//  Created by 孙一越 on 2018/3/28.
//  Copyright © 2018年 孙一越. All rights reserved.
//

#import <CCIMLib/CCIMLib.h>

@interface CCVoiceMessage : CCMessageContent

//发送语音消息 data应为一下格式的字符串

/**
  语音压缩base64编码
 */
@property(nonatomic, strong) NSString *content;

/**
 语音时长
 */
@property(nonatomic, strong) NSNumber *duration;
/**
 其他信息
 */
@property(nonatomic, strong) NSString *extra;

- (instancetype)initWithContent:(NSString *)content
                       duration:(NSNumber *)duration
                          extra:(NSString *)extra;
@end
