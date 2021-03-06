//
//  CCIMClient.h
//  CCIMLib
//
//  Created by 孙一越 on 2018/3/20.
//  Copyright © 2018年 孙一越. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CCMessage.h"
#import "MessageDraft.h"
#import "CCError.h"

#import "CCMessageContent.h"
#import "CCVoiceMessage.h"
#import "CCImageMessage.h"
#import "CCTextMessage.h"
#import "CCLocationMessage.h"

#import "CCGroupInfo.h"
#import "CCUploadMediaStatusListener.h"
//#import "CCFileMessage.h"
typedef void (^CCTokenInvalidBlock)(void);
typedef void (^CCNetworkErrorBlock)(NSString *msg);
typedef void (^CCLocalIntervalServerBLock)(NSTimeInterval timeInterval);
typedef enum {
    CCSingleConversation = 1,//单人会话类型
    CCGroupConversation = 3, //讨论组会话类型
    CCPublicConversation = 11 //公众号类型
}CCConversationType;

@protocol CCReceiveMessageDelegate <NSObject>



/*!
 接收消息的回调方法
 @param message     当前接收到的消息
 @param nLeft       还剩余的未接收的消息数，left>=0
 注意：设置并实现此Delegate监听消息接收；
 */
- (void)onReceived:(CCMessage *)message left:(int)nLeft;
/*!
 消息被撤回的回调方法
 
 @param messageId 被撤回的消息ID
 
 @discussion 被撤回的消息会变更为RCRecallNotificationMessage，App需要在UI上刷新这条消息。
 */
- (void)onMessageRecalled:(NSString *)messageId;
/**
 获取到会话中成员的已读状态

 @param conversationType 会话类型
 @param sid 会话ID
 @param statDict 会话成员已读到的消息msgid
                key为用户ID，value是该用户已读的消息ID
 */
- (void)onMessageReceiptResponse:(CCConversationType)conversationType
                             sid:(NSString *)sid
                        statDict:(NSDictionary *)statDict;
@end

@protocol CCTypingStatusDelegate<NSObject>
/*!
 用户输入状态变化的回调
 
 @param conversationType        会话类型
 @param sid                会话目标ID
 
 @discussion 当客户端收到用户输入状态的变化时，会回调此接口
 
 @warning 目前仅支持单聊。
 */
- (void)onTypingStatusChanged:(CCConversationType)conversationType
                     sid:(NSString *)sid;
@end

@interface CCIMClient : NSObject
/**
 *
 *parameters 服务器地址
 *
 */
@property (nonatomic, strong) NSString *ccService;
/**
 *
 *parameters 端口号
 *
 */
@property (nonatomic, strong) NSString *ccPort;

/**
 @brief 单例
 @discussion 获取该类单例进行操作
 @return 返回类实例
 */
+ (CCIMClient*)sharedCCIMClient;


/**
 * 处理网络异常
 */
@property (nonatomic, copy) CCNetworkErrorBlock ccNetworkErrorBlock;
#pragma mark - 初始化相关
/**
 系统初始化方法
 
 @param pushId  推送使用的deviceToken
 @param successBlock 连接成功
 @param errorBlock 错误信息
 */

- (void)connectWithToken:(NSString *)token
                       pushId:(NSString *)pushId
                      success:(void (^)(BOOL success))successBlock
                        error:(void(^)(CCError *error))errorBlock;

/**
 退出登录，sdk将不会接受到服务器的消息推送

 @param successBlock 成功消息
 @param errorBlock 错误信息
 */
- (void)userUnregisterSuccess:(void (^)(BOOL success,NSString *message))successBlock
                        error:(void(^)(CCError *error))errorBlock;
#pragma mark - 消息接收提醒
/**
 消息接收监听器
 */
@property(nonatomic, weak) id<CCReceiveMessageDelegate> receiveDelegate;
/**
 设置消息接收监听器
 
 @param delegate 消息接收监听器
 */
- (void)setReceiveMessageDelegate:(id<CCReceiveMessageDelegate>)delegate;

#pragma mark - 输入状态提醒
/**
 输入状态的监听器
 @warning 目前仅支持单聊。
 */
@property(nonatomic, weak) id<CCTypingStatusDelegate> typingDelegate;
/*!
 设置输入状态的监听器
 
 @param delegate 输入状态的的监听器
 
 @warning 目前仅支持单聊。
 */
- (void)setCCTypingStatusDelegate:(id<CCTypingStatusDelegate>)delegate;

#pragma mark - 消息相关
/**
 发送 文字、语音 消息
                                            必填
 @param conversationType 会话类型             是
 @param targetId 联系人ID/讨论组ID             是
 @param messageContent 消息的内容              是
 param successBlock 消息ID
 @param errorBlock 错误信息
 @return 发送的消息实体
 */
- (CCMessage *)sendMessage:(CCConversationType)conversationType
                  targetId:(NSString *)targetId
                   content:(CCMessageContent *)messageContent
                   success:(void (^)(NSString *messageId))successBlock
                     error:(void(^)(CCError *error,NSString *messageId))errorBlock;


/**
 发送媒体消息(上传图片或文件 媒体信息到指定的服务器)

 @param conversationType conversationType 会话类型
 @param targetId 联系人ID/讨论组ID
 @param messageContent 消息的内容
 @param uploadPrepareBlock 媒体文件上传进度更新的UI监听
 @param progressBlock 消息发送进度更新的回调
 @param successBlock 消息发送成功的回调 [messageId:消息的ID]
 @param errorBlock 消息发送失败的回调
 @return 发送的消息实体
 */
- (CCMessage *)sendMediaMessage:(CCConversationType)conversationType
                  targetId:(NSString *)targetId
                   content:(CCMessageContent *)messageContent
             uploadPrepare:(void (^)(CCUploadMediaStatusListener *uploadListener))uploadPrepareBlock
                  progress:(void (^)(int progress, NSString *messageId))progressBlock
                   success:(void (^)(NSString *messageId))successBlock
                     error:(void(^)(CCError *error,NSString *messageId))errorBlock;
/**
 发送自定义消息
                                            必填
 @param conversationType 会话类型             是
 @param targetId 联系人ID/讨论组ID             是
 @param mType 自定义消息类型(使用255以上的数字)   是
 @param messageContent 消息的内容              是
 @param search 服务器用于搜索的字段              是
 @param content  接收方离线时需要显示的远程推送内容    是
 @param successBlock 消息ID
 @param errorBlock 错误信息
  */
- (CCMessage *)sendCustomMessage:(CCConversationType)conversationType
                        targetId:(NSString *)targetId
                           mType:(NSNumber *)mType
                  messageContent:(CCMessageContent *)messageContent
                          search:(NSString *)search
                     pushContent:(NSString *)content
                         success:(void (^)(NSString *messageId))successBlock
                           error:(void(^)(CCError *error,NSString *messageId))errorBlock;

/**
 获取最近联系人/讨论组(全量/增量)
 
 @param size 获取最新会话列表最大条数，默认200
 @param successBlock 联系人/讨论组信息组成的数组
 @param errorBlock 错误信息 从本地数据读取的最新联系人数据
 */
- (void)getRecentContact:(NSInteger)size
                 success:(void (^)(NSArray *contactArray))successBlock
                   error:(void(^)(CCError *error,NSArray *contactArray))errorBlock;


/**
 获取某条消息ID之后的消息 重复调用该接口可以获取该消息ID之后的所有消息 获取消息列表按时间逆序返回
 
 @param sid 会话ID
 @param conversationType 会话类型
 @param size 获取消息列表长度，默认50
 @param messageId 本地存储的消息ID，获取该消息之后的消息, 如果messageId为空会获取当前会话最新size条数据
 @param successBlock recordArray msgs内为获取到的消息列表
 @param errorBlock 错误信息
 */
- (void)getNextRecord:(NSString *)sid
                 type:(CCConversationType)conversationType
                 size:(NSInteger)size
            messageId:(NSString *)messageId
              success:(void (^)(NSArray *recordArray))successBlock
                error:(void(^)(CCError *error))errorBlock;

/**
 获取某条消息ID之前更多的消息记录 如果没有消息ID，则表明获取最新的消息记录 消息数据按时间倒序返回
 
 @param sid 会话ID
 @param conversationType 会话类型
 @param size 获取消息列表长度
 @param messageId 本地存储的消息ID，获取该消息之后的消息  *****不存在则获取最新size条消息*****
 @param successBlock more为本次获得数据后续是否还存在数据 msgs内为获取到的消息列表
 @param errorBlock 错误信息
 */
- (void)getMoreRecord:(NSString *)sid
                 type:(CCConversationType)conversationType
                 size:(NSInteger)size
            messageId:(NSString *)messageId
              success:(void (^)(NSArray *recordArray))successBlock
                error:(void(^)(CCError *error))errorBlock;

/**
 获取会话中成员的已读状态
 
 @param sid 会话ID
 @param conversationType 会话类型
 使用 setReceiveMessageDelegate 方法设置代理   并实现此方法 onMessageReceiptResponse: 就会接收到该会话下成员的已读信息
 */

- (void)getReadStat:(NSString *)sid
               type:(CCConversationType)conversationType;

/**
 撤回自己发送的消息
 
 @param sid 会话ID
 @param conversationType 会话类型
 @param msgId 待撤回的消息ID
 @param successBlock 置已读成功success返回true
 @param errorBlock 错误信息
 */
- (void)chatRecall:(NSString *)sid
              type:(CCConversationType)conversationType
             msgId:(NSNumber *)msgId
           success:(void (^)(BOOL success))successBlock
             error:(void(^)(CCError *error))errorBlock;
/**
 将消息置为已读状态
 
 @param sid 会话ID
 @param conversationType 会话类型列表，见SessionType
 @param msgId 已读的消息ID（会话中最新的一条消息id）
 @param successBlock 置已读成功success返回true
 @param errorBlock 错误信息
 */
- (void)chatRead:(NSString *)sid
            type:(CCConversationType)conversationType
           msgId:(NSNumber *)msgId
         success:(void (^)(BOOL success))successBlock
           error:(void(^)(CCError *error))errorBlock;

/**
 会话消息输入，目前只支持1V1
 
 @param sid 会话ID
 @param conversationType 会话类型
 @param successBlock 成功时success为true 失败时success为false,返回错误信息msg
 @param errorBlock 错误信息
 */
- (void)chatTyping:(NSString *)sid
              type:(CCConversationType)conversationType
           success:(void (^)(BOOL success,NSString *message))successBlock
             error:(void(^)(CCError *error))errorBlock;

/**
 搜索指定会话中包含关键字的消息记录
 
 @param sid 会话ID
 @param conversationType 会话类型
 @param content 搜索关键字
 @param size 要获取的消息数量
 @param page 页数(可选,从1开始)
 @param successBlock 消息实体组成的数组
 @param errorBlock 错误信息
 */
- (void)chatSearch:(NSString *)sid
              type:(CCConversationType)conversationType
           content:(NSString *)content
              size:(NSInteger)size
              page:(NSInteger)page
           success:(void (^)(NSArray *recordArray))successBlock
             error:(void(^)(CCError *error))errorBlock;

/**
 搜索全部会话中包含关键字的消息记录
 
 @param content 搜索关键字
 @param size 要获取的消息数量
 @param page 页数(可选,从1开始)
 @param successBlock 消息实体组成的数组
 @param errorBlock 错误信息
 */
- (void)chatSearchAll:(NSString *)content
                 size:(NSInteger)size
                 page:(NSInteger)page
              success:(void (^)(NSArray *recordArray))successBlock
                error:(void(^)(CCError *error))errorBlock;


/**
 删除本地消息
 
 @param msgId 服务器中消息ID
 @return ture 删除成功  false 删除失败
 */
- (BOOL)deleteMessageByMsgId:(NSNumber *)msgId;

/*!
 通过messageId获取消息实体
 
 @param messageId   消息ID（数据库索引唯一值）
 @return            通过消息ID获取到的消息实体，当获取失败的时候，会返回nil。
 */
- (CCMessage *)getMessageByMessageId:(NSString *)messageId;

/**
 删除本地消息
 
 @param messageId 消息ID（数据库索引唯一值）
 @return ture 删除成功  false 删除失败
 */
- (BOOL)deleteMessageByMessageId:(NSString *)messageId;

#pragma mark - 群组相关
/**
 获取时间戳之后变化的讨论组信息
 登录初始化之后使用 以及 收到群组相关消息推送后调用
 @param successBlock 更新成功 或 失败
 */
- (void)queryDiscussionSuccess:(void (^)(BOOL success))successBlock;
/**
 创建讨论组
 
 @param userIdList 讨论组成员列表
 @param successBlock 返回 true 成功 false失败
 @param errorBlock 错误信息
 */
- (void)createDiscussionByUserIdList:(NSArray *)userIdList
                             success:(void (^)(BOOL success,CCGroupInfo *group,NSString *message))successBlock
                               error:(void (^)(CCError *error))errorBlock;

/**
 修改讨论组名称

 @param discussionId 讨论组ID
 @param discussionName 讨论组名称
 @param successBlock 返回 true 成功 false失败
 @param errorBlock 错误信息
 */
- (void)changeDiscussionNameById:(NSString *)discussionId
                            name:(NSString *)discussionName
                         success:(void (^)(BOOL success,NSString *message))successBlock
                           error:(void (^)(CCError *error))errorBlock;
/**
 讨论组添加成员
 
 @param discussionId 讨论组ID
 @param userIdList 新添讨论组成员
 @param successBlock 返回 讨论组成员列表
 @param errorBlock 错误信息
 
 备注
 
 members内为添加成员后讨论组成员列表，如果讨论组成员之前就存在讨论组中，也会返回成功
 */
- (void)addMemberToDiscussion:(NSString *)discussionId
                   userIdList:(NSArray *)userIdList
                      success:(void (^)(NSArray *memberList))successBlock
                        error:(void (^)(CCError *error))errorBlock;


/**
 获取讨论组信息 （成员列表 和 免打扰设置）


 @param discussionId 讨论组ID
 @return 讨论组信息
 */
- (CCGroupInfo *)getDiscussionInfoByDiscussionId:(NSString *)discussionId;

/**
 获取讨论组成员列表
 
 @param discussionId 讨论组ID
 @param successBlock 返回 讨论组成员列表
 @param errorBlock 错误信息
 */
- (void)getDiscussion:(NSString *)discussionId
              success:(void (^)(NSArray *memberList))successBlock
                error:(void (^)(CCError *error))errorBlock;

/**
 将用户移出讨论组
 
 @param discussionId 讨论组ID
 @param userIds 移除讨论组成员
 @param successBlock 返回 讨论组成员列表
 @param errorBlock 错误信息
 
 备注
 
 members内为移除成员后讨论组成员列表，如果讨论组成员之前不存在，也会返回成功
 */
- (void)removeMemberFromDiscussion:(NSString *)discussionId
                           userIds:(NSArray *)userIds
                           success:(void (^)(NSArray *memberList))successBlock
                             error:(void (^)(CCError *error))errorBlock;

/**
 设置讨论组免打扰功能

 @param discussionId 讨论组ID
 @param muted 讨论组是否免打扰
 @param successBlock 返回 true 成功 false失败
 @param errorBlock 错误信息
 */
- (void)muteDiscussionById:(NSString *)discussionId
                     muted:(BOOL)muted
                   success:(void (^)(BOOL success))successBlock
                     error:(void (^)(CCError *error))errorBlock;
#pragma mark 数据库路径

/**
 获取本地数据库路径
 */
- (NSURL *)getMsgDBPath;
#pragma mark - 草稿相关
/*!
 保存草稿信息
 
 @param messageDraft        草稿对象
 @return                    是否保存成功
 */
- (BOOL)saveTextMessageDraft:(MessageDraft *)messageDraft;
/*!
 获取会话中的草稿信息
 
 @param conversationType     会话类型
 @param targetId            会话ID
 @return                    该会话中的草稿
 */
- (MessageDraft *)getTextMessageDraft:(CCConversationType )conversationType
                             targetId:(NSString *)targetId;

/*!
 删除会话中的草稿信息
 
 @param cType     会话类型，同Session.type
 1    单人会话
 3    讨论组会话
 @param targetId            会话ID
 @return                    是否删除成功
 */
- (BOOL)clearTextMessageDraft:(NSNumber *)cType
                     targetId:(NSString *)targetId;
@end

