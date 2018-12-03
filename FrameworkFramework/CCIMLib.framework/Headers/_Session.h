// DO NOT EDIT. This file is machine-generated and constantly overwritten.
// Make changes to Session.h instead.

#if __has_feature(modules)
    @import Foundation;
    @import CoreData;
#else
    #import <Foundation/Foundation.h>
    #import <CoreData/CoreData.h>
#endif

NS_ASSUME_NONNULL_BEGIN

@interface SessionID : NSManagedObjectID {}
@end

@interface _Session : NSManagedObject
+ (instancetype)insertInManagedObjectContext:(NSManagedObjectContext *)moc_;
+ (NSString*)entityName;
+ (nullable NSEntityDescription*)entityInManagedObjectContext:(NSManagedObjectContext*)moc_;
@property (nonatomic, readonly, strong) SessionID *objectID;

@property (nonatomic, strong, nullable) NSNumber* cnt;

@property (atomic) int32_t cntValue;
- (int32_t)cntValue;
- (void)setCntValue:(int32_t)value_;

@property (nonatomic, strong, nullable) NSString* draft;

@property (nonatomic, strong, nullable) NSString* id;

@property (nonatomic, strong, nullable) NSNumber* readMsgId;

@property (atomic) int64_t readMsgIdValue;
- (int64_t)readMsgIdValue;
- (void)setReadMsgIdValue:(int64_t)value_;

@property (nonatomic, strong, nullable) NSNumber* timestamp;

@property (atomic) int64_t timestampValue;
- (int64_t)timestampValue;
- (void)setTimestampValue:(int64_t)value_;

@property (nonatomic, strong, nullable) NSNumber* type;

@property (atomic) int32_t typeValue;
- (int32_t)typeValue;
- (void)setTypeValue:(int32_t)value_;

@end

@interface _Session (CoreDataGeneratedPrimitiveAccessors)

- (nullable NSNumber*)primitiveCnt;
- (void)setPrimitiveCnt:(nullable NSNumber*)value;

- (int32_t)primitiveCntValue;
- (void)setPrimitiveCntValue:(int32_t)value_;

- (nullable NSString*)primitiveDraft;
- (void)setPrimitiveDraft:(nullable NSString*)value;

- (nullable NSString*)primitiveId;
- (void)setPrimitiveId:(nullable NSString*)value;

- (nullable NSNumber*)primitiveReadMsgId;
- (void)setPrimitiveReadMsgId:(nullable NSNumber*)value;

- (int64_t)primitiveReadMsgIdValue;
- (void)setPrimitiveReadMsgIdValue:(int64_t)value_;

- (nullable NSNumber*)primitiveTimestamp;
- (void)setPrimitiveTimestamp:(nullable NSNumber*)value;

- (int64_t)primitiveTimestampValue;
- (void)setPrimitiveTimestampValue:(int64_t)value_;

@end

@interface SessionAttributes: NSObject 
+ (NSString *)cnt;
+ (NSString *)draft;
+ (NSString *)id;
+ (NSString *)readMsgId;
+ (NSString *)timestamp;
+ (NSString *)type;
@end

NS_ASSUME_NONNULL_END
