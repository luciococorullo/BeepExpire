/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2020- Scandit AG. All rights reserved.
 */

#import <Foundation/Foundation.h>

#import <ScanditCaptureCore/SDCBase.h>

NS_ASSUME_NONNULL_BEGIN

@protocol SDCLocationSelection;

NS_SWIFT_NAME(LocationSelectionDeserializer)
SDC_EXPORTED_SYMBOL
@interface SDCLocationSelectionDeserializer : NSObject

@property (nonatomic, readonly) NSArray<NSString *> *warnings;

+ (nonnull instancetype)locationSelectionDeserializer;

// clang-format off
- (nullable id<SDCLocationSelection>)locationSelectionFromJSONString:(nonnull NSString *)JSONString
                                                               error:(NSError *_Nullable *_Nullable)error;
// clang-format on

@end

NS_ASSUME_NONNULL_END
