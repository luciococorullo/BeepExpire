/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2018- Scandit AG. All rights reserved.
 */

#define SDC_EXPORTED_SYMBOL __attribute__((visibility("default")))

#if !defined(SDC_EXTERN)
#    if defined(__cplusplus)
#        define SDC_EXTERN extern "C" SDC_EXPORTED_SYMBOL
#    else
#        define SDC_EXTERN extern SDC_EXPORTED_SYMBOL
#    endif
#endif

/* !defined(SDC_EXTERN) */
