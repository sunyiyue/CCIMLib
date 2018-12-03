//
//  CCLocationMessage.h
//  CCIMLib
//
//  Created by 孙一越 on 2018/5/21.
//  Copyright © 2018年 孙一越. All rights reserved.
//

#import <CCIMLib/CCIMLib.h>

@interface CCLocationMessage : CCMessageContent

/**
 纬度
 */
@property(nonatomic, strong)NSNumber *latitude;

/**
 经度
 */
@property(nonatomic, strong)NSNumber *longitude;

/**
 兴趣点信息
 */
@property(nonatomic, strong)NSString *poi;

/**
 地图缩略图base64编码
 */
@property(nonatomic, strong)NSString *content;

/**
 extra
 */
@property(nonatomic, strong)NSString *extra;

- (instancetype)initWithLocationContent:(NSString *)content
                                  latitude:(NSNumber *)latitude
                                  longitude:(NSNumber *)longitude
                                     poi:(NSString *)poi
                                     extra:(NSString *)extra;
@end
