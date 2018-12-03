//
//  CCMessage.h
//  CCIMLib
//
//  Created by 孙一越 on 2018/3/21.
//  Copyright © 2018年 孙一越. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Message.h"
@interface CCMessage : NSObject
/*!
 本地存储的消息ID
 
 @discussion 本地存储的消息的唯一值（数据库索引唯一值）
 */
@property(nonatomic, strong) NSString *messageId;
/*!
 服务器中消息ID
 
 @discussion 服务器消息唯一ID
 */
@property(nonatomic, strong) NSNumber *msgId;
/**
 消息类型 文字 图片 语音
 字段    含义
 1    本文消息
 2    图片消息
 4    文件消息
 5    语音消息
 6    系统消息
 7    地点消息
 51    被撤回的消息
 101    撤回消息
 52    讨论组通知
 200     控制消息
 255+    自定义消息   
 */
@property (nonatomic,strong)NSNumber *mType;
/**
 会话ID，同Session.id
 */
@property (nonatomic,strong)NSString *sid;
/**
 会话类型，同Session.type
 1    单人会话
 3    讨论组会话
 11    公众号
 */
@property (nonatomic,strong)NSNumber *cType;
/**
 发送人ID
 */
@property (nonatomic,strong)NSString *sender;
/**
 消息实体内容字段，可用于直接展示
 */
@property (nonatomic,strong)NSString *content;
/**
 服务器消息搜索字段,返回的数据并不含有该数据
 */
@property (nonatomic,strong)NSString *search;

/**
 消息体内容，json数据传，详情见消息类型
 字段    含义                消息体
 1    本文消息TextMessage    String
 2    图片消息ImgMessage    {imageUri:String, // 图片下载地址 content:String, // 图片缩略图base64编码 extra:String // 其他信息}
 4    文件消息FileMessage    {name:String, // 文件名称 fileUri:String, // 文件下载地址size:Number, // 文件大小mimeType:String, // 文件类型extra:String // 其他信息}
 5    语音消息VoiceMessage    {content:String, // 语音压缩base64编码duration:Number, // 语音时长extra:String //其他信息}
 6    系统消息SysMessage    ???
 7    地点消息LocationMessage    {latitude:Number, // 纬度longitude:Number, // 经度poi:String, // 兴趣点信息content:String, // 地图缩略图base64编码extra:String // 其他信息}
 51    被撤回的消息RecallMessage   String // 撤回消息ID
 52   讨论组通知GroupNotifyMessage  {oper:String, // 操作operator:String, // 操作人IDoperands:[String,String...], // 被操作人ID列表content:String // 被操作的内容,修改讨论组名称时使用}
 101    撤回消息RecallMessage    String // 撤回消息ID
 200   控制消息ControlMessage    ???
 255+    自定义消息    String
 */
@property (nonatomic,strong)NSString *data;
/**
 消息发送时间戳 格式举例：1524464181992

 */
@property (nonatomic,strong)NSNumber *timestamp;
/**
 该条消息中是否被@到
 */
@property (nonatomic,assign)BOOL at;


/** sy
 消息发送状态 0 正在发送  -1 失败  1 成功
 */
@property (nonatomic,strong)NSString *msgStatus;


- (instancetype)initWith:(Message *)message;
@end
