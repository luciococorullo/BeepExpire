/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2020- Scandit AG. All rights reserved.
 */

#import <Foundation/Foundation.h>

#import <ScanditCaptureCore/SDCBase.h>

NS_ASSUME_NONNULL_BEGIN

NS_SWIFT_NAME(DataCaptureContextSettings)
SDC_EXPORTED_SYMBOL
@interface SDCDataCaptureContextSettings : NSObject

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

+ (instancetype)settings;

- (void)setValue:(nullable id)value
     forProperty:(nonnull NSString *)property NS_SWIFT_NAME(set(value:forProperty:));
- (nullable id)valueForProperty:(nonnull NSString *)property;

@end

NS_ASSUME_NONNULL_END
