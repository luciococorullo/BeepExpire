/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2018- Scandit AG. All rights reserved.
 */

#import <Foundation/Foundation.h>

#import <ScanditCaptureCore/SDCBase.h>

NS_ASSUME_NONNULL_BEGIN

NS_SWIFT_NAME(Vibration)
SDC_EXPORTED_SYMBOL
@interface SDCVibration : NSObject

@property (class, nonatomic, readonly) SDCVibration *defaultVibration;
@property (class, nonatomic, readonly) SDCVibration *selectionHapticFeedback;
@property (class, nonatomic, readonly) SDCVibration *successHapticFeedback;
@property (class, nonatomic, readonly) SDCVibration *impactHapticFeedback;
@property (nonatomic, nonnull, readonly) NSString *JSONString;

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
