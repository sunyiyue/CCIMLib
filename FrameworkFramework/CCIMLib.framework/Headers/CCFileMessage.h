//
//  CCFileMessage.h
//  CCIMLib
//
//  Created by 孙一越 on 2018/3/28.
//  Copyright © 2018年 孙一越. All rights reserved.
//

#import <CCIMLib/CCIMLib.h>

@interface CCFileMessage : CCMessageContent

//发送文件消息
/**
 文件名字
 */
@property(nonatomic, strong) NSString *name;
/**
 文件下载地址
 */
@property(nonatomic, strong) NSString *fileUri;

/**
 文件大小
 */
@property(nonatomic, strong) NSNumber *size;
/**
 文件类型
 */
@property(nonatomic, strong) NSString *mimeType;
/**
 附加信息
 */
@property(nonatomic, strong) NSString *extra;

/** 可选
 文件在本地的位置
 */
@property(nonatomic, strong) NSString *localPath;
//初始化方法
- (instancetype)initWithName:(NSString *)name
                        size:(NSNumber *)size
                    mimeType:(NSString *)mimeType
                       extra:(NSString *)extra
                   localPath:(NSString *)localPath;
@end
