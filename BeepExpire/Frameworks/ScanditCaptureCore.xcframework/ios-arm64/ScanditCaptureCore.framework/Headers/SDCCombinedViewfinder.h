/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2020 Scandit AG. All rights reserved.
 */

#import <ScanditCaptureCore/SDCBase.h>
#import <ScanditCaptureCore/SDCMeasureUnit.h>
#import <ScanditCaptureCore/SDCViewfinder.h>

NS_ASSUME_NONNULL_BEGIN

NS_SWIFT_NAME(CombinedViewfinder)
SDC_EXPORTED_SYMBOL
@interface SDCCombinedViewfinder : NSObject <SDCViewfinder>

+ (nonnull instancetype)viewfinder;

- (void)addViewfinder:(nonnull id<SDCViewfinder>)viewfinder;
- (void)addViewfinder:(nonnull id<SDCViewfinder>)viewfinder
    withPointOfInterest:(SDCPointWithUnit)pointOfInterest;
- (void)removeViewfinder:(nonnull id<SDCViewfinder>)viewfinder;
- (void)removeAll;

@end

NS_ASSUME_NONNULL_END
