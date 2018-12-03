// DO NOT EDIT. This file is machine-generated and constantly overwritten.
// Make changes to Group.h instead.

#if __has_feature(modules)
    @import Foundation;
    @import CoreData;
#else
    #import <Foundation/Foundation.h>
    #import <CoreData/CoreData.h>
#endif

NS_ASSUME_NONNULL_BEGIN

@interface GroupID : NSManagedObjectID {}
@end

@interface _Group : NSManagedObject
+ (instancetype)insertInManagedObjectContext:(NSManagedObjectContext *)moc_;
+ (NSString*)entityName;
+ (nullable NSEntityDescription*)entityInManagedObjectContext:(NSManagedObjectContext*)moc_;
@property (nonatomic, readonly, strong) GroupID *objectID;

@property (nonatomic, strong, nullable) NSString* groupId;

@property (nonatomic, strong, nullable) NSData* memberArray;

@property (nonatomic, strong, nullable) NSNumber* muted;

@property (atomic) BOOL mutedValue;
- (BOOL)mutedValue;
- (void)setMutedValue:(BOOL)value_;

@end

@interface _Group (CoreDataGeneratedPrimitiveAccessors)

- (nullable NSString*)primitiveGroupId;
- (void)setPrimitiveGroupId:(nullable NSString*)value;

- (nullable NSData*)primitiveMemberArray;
- (void)setPrimitiveMemberArray:(nullable NSData*)value;

- (nullable NSNumber*)primitiveMuted;
- (void)setPrimitiveMuted:(nullable NSNumber*)value;

- (BOOL)primitiveMutedValue;
- (void)setPrimitiveMutedValue:(BOOL)value_;

@end

@interface GroupAttributes: NSObject 
+ (NSString *)groupId;
+ (NSString *)memberArray;
+ (NSString *)muted;
@end

NS_ASSUME_NONNULL_END
