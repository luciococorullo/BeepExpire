/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2020- Scandit AG. All rights reserved.
 */

#include <Foundation/Foundation.h>

#include <ScanditCaptureCore/SDCBase.h>

NS_ASSUME_NONNULL_BEGIN

NS_SWIFT_NAME(DataCaptureComponent)
SDC_EXPORTED_SYMBOL
@protocol SDCDataCaptureComponent <NSObject>

@property (nonatomic, readonly) NSString *componentId;

@end

NS_ASSUME_NONNULL_END
