/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2020- Scandit AG. All rights reserved.
 */

#import <ScanditCaptureCore/SDCBase.h>
#import <ScanditCaptureCore/SDCViewfinder.h>

@class UIColor;

NS_ASSUME_NONNULL_BEGIN

NS_SWIFT_NAME(AimerViewfinder)
SDC_EXPORTED_SYMBOL
@interface SDCAimerViewfinder : NSObject <SDCViewfinder>

+ (nonnull instancetype)viewfinder;

@property (nonatomic, strong, nonnull) UIColor *frameColor;
@property (nonatomic, strong, nonnull) UIColor *dotColor;

@end

NS_ASSUME_NONNULL_END
