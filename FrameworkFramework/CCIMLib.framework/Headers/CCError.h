//
//  CCError.h
//  CCIMLib
//
//  Created by 孙一越 on 2018/3/27.
//  Copyright © 2018年 孙一越. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface CCError : NSObject
/**
 返回代码值
 */
@property (nonatomic,assign) NSInteger code;
/**
 请求数据失败原因
 */
@property (nonatomic,strong) NSString *message;
- (instancetype)initWith:(NSInteger)code message:(NSString *)message;
@end
