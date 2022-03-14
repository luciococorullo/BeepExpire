/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2020- Scandit AG. All rights reserved.
 */

#import <Foundation/Foundation.h>
#import <ScanditCaptureCore/SDCBase.h>
#import <ScanditBarcodeCapture/SDCCompositeType.h>

NS_ASSUME_NONNULL_BEGIN

NS_SWIFT_NAME(CompositeTypeDescription)
SDC_EXPORTED_SYMBOL
@interface SDCCompositeTypeDescription : NSObject

@property (class, nonatomic, nonnull, readonly)
    NSArray<SDCCompositeTypeDescription *> *allCompositeTypeDescriptions NS_SWIFT_NAME(all);

@property (nonatomic, nonnull, readonly) NSSet<NSNumber *> *symbologies;
@property (nonatomic, nonnull, readonly) NSString *JSONString;
@property (nonatomic, readonly) SDCCompositeType compositeTypes;

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

+ (SDCCompositeTypeDescription *)descriptionFromCompositeType:(SDCCompositeType)compositeType;
- (instancetype)initWithCompositeType:(SDCCompositeType)compositeType NS_DESIGNATED_INITIALIZER;

@end

NS_ASSUME_NONNULL_END
