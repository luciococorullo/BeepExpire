/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2017- Scandit AG. All rights reserved.
 */

#import <Foundation/Foundation.h>

#import <ScanditCaptureCore/SDCBase.h>
#import <ScanditBarcodeCapture/SDCSymbology.h>

NS_ASSUME_NONNULL_BEGIN

NS_SWIFT_NAME(SymbologySettings)
SDC_EXPORTED_SYMBOL
@interface SDCSymbologySettings : NSObject

@property (nonatomic, readonly) SDCSymbology symbology;
@property (nonatomic, assign, getter=isEnabled) BOOL enabled NS_SWIFT_NAME(isEnabled);
@property (nonatomic, assign, getter=isColorInvertedEnabled)
    BOOL colorInvertedEnabled NS_SWIFT_NAME(isColorInvertedEnabled);
@property (nonatomic, assign) SDCChecksum checksums;
@property (nonatomic, nonnull, readonly) NSSet<NSString *> *enabledExtensions;
@property (nonatomic, strong) NSSet<NSNumber *> *activeSymbolCounts;
@property (nonatomic, nonnull, readonly) NSString *JSONString;

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

- (BOOL)isExtensionEnabled:(nonnull NSString *)extension;
- (void)setExtension:(nonnull NSString *)extension
             enabled:(BOOL)enabled NS_SWIFT_NAME(set(extension:enabled:));

@end

NS_ASSUME_NONNULL_END
