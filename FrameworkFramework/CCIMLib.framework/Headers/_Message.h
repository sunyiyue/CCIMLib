// DO NOT EDIT. This file is machine-generated and constantly overwritten.
// Make changes to Message.h instead.

#if __has_feature(modules)
    @import Foundation;
    @import CoreData;
#else
    #import <Foundation/Foundation.h>
    #import <CoreData/CoreData.h>
#endif

NS_ASSUME_NONNULL_BEGIN

@interface MessageID : NSManagedObjectID {}
@end

@interface _Message : NSManagedObject
+ (instancetype)insertInManagedObjectContext:(NSManagedObjectContext *)moc_;
+ (NSString*)entityName;
+ (nullable NSEntityDescription*)entityInManagedObjectContext:(NSManagedObjectContext*)moc_;
@property (nonatomic, readonly, strong) MessageID *objectID;

@property (nonatomic, strong, nullable) NSNumber* at;

@property (atomic) BOOL atValue;
- (BOOL)atValue;
- (void)setAtValue:(BOOL)value_;

@property (nonatomic, strong, nullable) NSData* atList;

@property (nonatomic, strong, nullable) NSNumber* cType;

@property (atomic) int32_t cTypeValue;
- (int32_t)cTypeValue;
- (void)setCTypeValue:(int32_t)value_;

@property (nonatomic, strong, nullable) NSString* content;

@property (nonatomic, strong, nullable) NSString* data;

@property (nonatomic, strong, nullable) NSNumber* mType;

@property (atomic) int32_t mTypeValue;
- (int32_t)mTypeValue;
- (void)setMTypeValue:(int32_t)value_;

@property (nonatomic, strong, nullable) NSString* messageId;

@property (nonatomic, strong, nullable) NSNumber* msgId;

@property (atomic) int64_t msgIdValue;
- (int64_t)msgIdValue;
- (void)setMsgIdValue:(int64_t)value_;

@property (nonatomic, strong, nullable) NSString* msgStatus;

@property (nonatomic, strong, nullable) NSData* receiveList;

@property (nonatomic, strong, nullable) NSString* search;

@property (nonatomic, strong, nullable) NSString* sender;

@property (nonatomic, strong, nullable) NSString* sid;

@property (nonatomic, strong, nullable) NSNumber* timestamp;

@property (atomic) int64_t timestampValue;
- (int64_t)timestampValue;
- (void)setTimestampValue:(int64_t)value_;

@end

@interface _Message (CoreDataGeneratedPrimitiveAccessors)

- (nullable NSNumber*)primitiveAt;
- (void)setPrimitiveAt:(nullable NSNumber*)value;

- (BOOL)primitiveAtValue;
- (void)setPrimitiveAtValue:(BOOL)value_;

- (nullable NSData*)primitiveAtList;
- (void)setPrimitiveAtList:(nullable NSData*)value;

- (nullable NSNumber*)primitiveCType;
- (void)setPrimitiveCType:(nullable NSNumber*)value;

- (int32_t)primitiveCTypeValue;
- (void)setPrimitiveCTypeValue:(int32_t)value_;

- (nullable NSString*)primitiveContent;
- (void)setPrimitiveContent:(nullable NSString*)value;

- (nullable NSString*)primitiveData;
- (void)setPrimitiveData:(nullable NSString*)value;

- (nullable NSNumber*)primitiveMType;
- (void)setPrimitiveMType:(nullable NSNumber*)value;

- (int32_t)primitiveMTypeValue;
- (void)setPrimitiveMTypeValue:(int32_t)value_;

- (nullable NSString*)primitiveMessageId;
- (void)setPrimitiveMessageId:(nullable NSString*)value;

- (nullable NSNumber*)primitiveMsgId;
- (void)setPrimitiveMsgId:(nullable NSNumber*)value;

- (int64_t)primitiveMsgIdValue;
- (void)setPrimitiveMsgIdValue:(int64_t)value_;

- (nullable NSString*)primitiveMsgStatus;
- (void)setPrimitiveMsgStatus:(nullable NSString*)value;

- (nullable NSData*)primitiveReceiveList;
- (void)setPrimitiveReceiveList:(nullable NSData*)value;

- (nullable NSString*)primitiveSearch;
- (void)setPrimitiveSearch:(nullable NSString*)value;

- (nullable NSString*)primitiveSender;
- (void)setPrimitiveSender:(nullable NSString*)value;

- (nullable NSString*)primitiveSid;
- (void)setPrimitiveSid:(nullable NSString*)value;

- (nullable NSNumber*)primitiveTimestamp;
- (void)setPrimitiveTimestamp:(nullable NSNumber*)value;

- (int64_t)primitiveTimestampValue;
- (void)setPrimitiveTimestampValue:(int64_t)value_;

@end

@interface MessageAttributes: NSObject 
+ (NSString *)at;
+ (NSString *)atList;
+ (NSString *)cType;
+ (NSString *)content;
+ (NSString *)data;
+ (NSString *)mType;
+ (NSString *)messageId;
+ (NSString *)msgId;
+ (NSString *)msgStatus;
+ (NSString *)receiveList;
+ (NSString *)search;
+ (NSString *)sender;
+ (NSString *)sid;
+ (NSString *)timestamp;
@end

NS_ASSUME_NONNULL_END
