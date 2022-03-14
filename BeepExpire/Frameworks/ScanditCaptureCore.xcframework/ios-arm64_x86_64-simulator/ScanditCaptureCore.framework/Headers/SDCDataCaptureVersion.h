/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2020- Scandit AG. All rights reserved.
 */

#import <Foundation/Foundation.h>

#import <ScanditCaptureCore/SDCBase.h>

NS_ASSUME_NONNULL_BEGIN

NS_SWIFT_NAME(DataCaptureVersion)
SDC_EXPORTED_SYMBOL
@interface SDCDataCaptureVersion : NSObject

@property (class, nonatomic, nonnull, readonly) NSString *version;

@end

NS_ASSUME_NONNULL_END
