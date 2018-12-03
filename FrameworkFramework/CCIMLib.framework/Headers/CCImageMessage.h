//
//  CCImageMessage.h
//  CCIMLib
//
//  Created by 孙一越 on 2018/3/28.
//  Copyright © 2018年 孙一越. All rights reserved.
//

#import <CCIMLib/CCIMLib.h>

@interface CCImageMessage : CCMessageContent
//发送图片消息

/**
 图片下载地址
 */
@property(nonatomic, strong) NSString *imageUri;

/**
 图片缩略图base64编码
 */
@property(nonatomic, strong) NSString *content;

/**
 附加信息
 */
@property(nonatomic, strong) NSString *extra;

//初始化方法
- (instancetype)initWithContent:(NSString *)content
                           extra:(NSString *)extra;
@end
