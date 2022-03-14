/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2019- Scandit AG. All rights reserved.
 */

#import <Foundation/Foundation.h>

#import <ScanditCaptureCore/SDCMeasureUnit.h>

NS_ASSUME_NONNULL_BEGIN

NS_SWIFT_NAME(SizeWithUnitAndAspect)
@interface SDCSizeWithUnitAndAspect : NSObject

@property (nonatomic, readonly) SDCSizeWithUnit widthAndHeight;
@property (nonatomic, readonly) SDCSizeWithAspect widthAndAspectRatio;
@property (nonatomic, readonly) SDCSizeWithAspect heightAndAspectRatio;
@property (nonatomic, readonly) SDCSizeWithAspect shorterDimensionAndAspectRatio;
@property (nonatomic, readonly) SDCSizingMode sizingMode;

@property (nonatomic, nonnull, readonly) NSString *JSONString;

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
