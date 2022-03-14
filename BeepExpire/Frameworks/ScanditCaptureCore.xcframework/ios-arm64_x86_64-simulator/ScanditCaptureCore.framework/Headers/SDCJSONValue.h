/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2019- Scandit AG. All rights reserved.
 */

#import <UIKit/UIKit.h>

#import <ScanditCaptureCore/SDCBase.h>
#import <ScanditCaptureCore/SDCMeasureUnit.h>

@class SDCBrush;
@class SDCSizeWithUnitAndAspect;

NS_ASSUME_NONNULL_BEGIN

NS_SWIFT_NAME(JSONValue)
SDC_EXPORTED_SYMBOL
@interface SDCJSONValue : NSObject

@property (nonatomic, assign, getter=isUsed) BOOL used;
@property (nonatomic, strong, readonly) NSString *absolutePath;

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

+ (instancetype)JSONValueWithString:(nonnull NSString *)string;

- (nonnull NSString *)jsonString;

- (BOOL)asBOOL;
- (BOOL)BOOLForKey:(nonnull NSString *)key;
- (BOOL)BOOLForKey:(nonnull NSString *)key default:(BOOL)defaultValue;

- (NSInteger)asInteger;
- (NSInteger)integerForKey:(nonnull NSString *)key;
- (NSInteger)integerForKey:(nonnull NSString *)key default:(NSInteger)defaultValue;

- (CGFloat)asCGFloat;
- (CGFloat)CGFloatForKey:(nonnull NSString *)key;
- (CGFloat)CGFloatForKey:(nonnull NSString *)key default:(CGFloat)defaultValue;

- (nonnull NSString *)asString;
- (nonnull NSString *)stringForKey:(nonnull NSString *)key;
- (nonnull NSString *)stringForKey:(nonnull NSString *)key default:(nonnull NSString *)defaultValue;

- (nonnull UIColor *)asColor;
- (nonnull UIColor *)colorForKey:(nonnull NSString *)key;
- (nonnull UIColor *)colorForKey:(nonnull NSString *)key default:(nonnull UIColor *)defaultValue;

- (nonnull SDCBrush *)asBrush;
- (nonnull SDCBrush *)brushForKey:(nonnull NSString *)key;
- (nullable SDCBrush *)brushForKey:(nonnull NSString *)key
                           default:(nullable SDCBrush *)defaultValue;

- (SDCFloatWithUnit)asFloatWithUnit;
- (SDCFloatWithUnit)floatWithUnitForKey:(nonnull NSString *)key;
- (SDCFloatWithUnit)floatWithUnitForKey:(nonnull NSString *)key
                                default:(SDCFloatWithUnit)defaultValue;

- (SDCPointWithUnit)asPointWithUnit;
- (SDCPointWithUnit)pointWithUnitForKey:(nonnull NSString *)key;
- (SDCPointWithUnit)pointWithUnitForKey:(nonnull NSString *)key
                                default:(SDCPointWithUnit)defaultValue;

- (SDCMarginsWithUnit)asMarginsWithUnit;
- (SDCMarginsWithUnit)marginsWithUnitForKey:(nonnull NSString *)key;
- (SDCMarginsWithUnit)marginsWithUnitForKey:(nonnull NSString *)key
                                    default:(SDCMarginsWithUnit)defaultValue;

- (nonnull SDCJSONValue *)asArray;
- (nonnull SDCJSONValue *)arrayForKey:(nonnull NSString *)key;
- (nullable SDCJSONValue *)arrayForKey:(nonnull NSString *)key
                               default:(nullable SDCJSONValue *)defaultValue;
- (NSUInteger)count;
- (nonnull SDCJSONValue *)JSONValueAtIndex:(NSUInteger)index;

- (nonnull SDCJSONValue *)asObject;
- (nonnull SDCJSONValue *)objectForKey:(nonnull NSString *)key;
- (nullable SDCJSONValue *)objectForKey:(nonnull NSString *)key
                                default:(nullable SDCJSONValue *)defaultValue;
- (BOOL)containsKey:(nonnull NSString *)key;

@end

NS_ASSUME_NONNULL_END
