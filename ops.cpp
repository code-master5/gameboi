bool not_imp(cpu* c)
{
	uint8_t opcode = c->read(c->pc);
	printf("operation decimal : %d, hex: %x not implemented yet!\n", opcode, opcode);
	return false;
}

operation op("Dummy", 0, 0, not_imp);

// Function for all load type operations
bool ld(cpu* c) 
{
	uint8_t opcode = c->read(c->pc);
	switch(opcode) 
	{
		case 0x31: { 
			// this loads the stack pointer with 2 byte immediate value
			// assuming that lower bits are given first
			uint16_t low = c->read(c->pc + 1);
			uint16_t high = c->read(c->pc + 2);
			low = (high << 8) | low;
			c->sp = low;
			break;
		}
		case 0x21: {
			// LD HL nn
			c->l = c->read(c ->pc + 1);
			c->h = c->read(c->pc + 2);
			break;
		}
		case 0x32: {
			// load value from address at hl into a and 
			// decrement hl
			uint16_t addr = (((uint16_t)c->h) << 8) | (c -> l);
			printf("hello\n");
			printf("trying to read %x\n", addr);
			c->write(addr, c->a);
			printf("hi\n");
			addr--;
			c->l = addr;
			c->h = addr >> 8;
			break;
		}
		default:
			return false;
	}
	return true;
}

bool xorop(cpu* c) 
{
	uint8_t opcode = c->read(c->pc);
	switch(opcode) {
			case 0xaf: {
				// xor a with itself
				c->a = 0;
				c->zero = 1;
				break;
			}
			default:
				return false;
	}
	c->carry = c->half_carry = c->subtract = 0;
	return true;
}

operation inst_set[512] = {
// 0
op, 
// 1
op, 
// 2
op, 
// 3
op, 
// 4
op, 
// 5
op, 
// 6
op, 
// 7
op, 
// 8
op, 
// 9
op, 
// 10
op, 
// 11
op, 
// 12
op, 
// 13
op, 
// 14
op, 
// 15
op, 
// 16
op, 
// 17
op, 
// 18
op, 
// 19
op, 
// 20
op, 
// 21
op, 
// 22
op, 
// 23
op, 
// 24
op, 
// 25
op, 
// 26
op, 
// 27
op, 
// 28
op, 
// 29
op, 
// 30
op, 
// 31
op,
// 32
op, 
// 33
operation("LD HL nn", 3, 12, ld), 
// 34
op, 
// 35
op, 
// 36
op, 
// 37
op, 
// 38
op, 
// 39
op, 
// 40
op, 
// 41
op, 
// 42
op, 
// 43
op, 
// 44
op, 
// 45
op, 
// 46
op, 
// 47
op, 
// 48
op, 
// 49
operation("LD SP nn", 3, 12, ld), 
// 50
operation("LDD HL A", 1, 8, ld), 
// 51
op, 
// 52
op, 
// 53
op, 
// 54
op, 
// 55
op, 
// 56
op, 
// 57
op, 
// 58
op, 
// 59
op, 
// 60
op, 
// 61
op, 
// 62
op, 
// 63
op, 
// 64
op, 
// 65
op, 
// 66
op, 
// 67
op, 
// 68
op, 
// 69
op, 
// 70
op, 
// 71
op, 
// 72
op, 
// 73
op, 
// 74
op, 
// 75
op, 
// 76
op, 
// 77
op, 
// 78
op, 
// 79
op, 
// 80
op, 
// 81
op, 
// 82
op, 
// 83
op, 
// 84
op, 
// 85
op, 
// 86
op, 
// 87
op, 
// 88
op, 
// 89
op, 
// 90
op, 
// 91
op, 
// 92
op, 
// 93
op, 
// 94
op, 
// 95
op, 
// 96
op, 
// 97
op, 
// 98
op, 
// 99
op, 
// 100
op, 
// 101
op, 
// 102
op, 
// 103
op, 
// 104
op, 
// 105
op, 
// 106
op, 
// 107
op, 
// 108
op, 
// 109
op, 
// 110
op, 
// 111
op, 
// 112
op, 
// 113
op, 
// 114
op, 
// 115
op, 
// 116
op, 
// 117
op, 
// 118
op, 
// 119
op, 
// 120
op, 
// 121
op, 
// 122
op, 
// 123
op, 
// 124
op, 
// 125
op, 
// 126
op, 
// 127
op, 
// 128
op, 
// 129
op, 
// 130
op, 
// 131
op, 
// 132
op, 
// 133
op, 
// 134
op, 
// 135
op, 
// 136
op, 
// 137
op, 
// 138
op, 
// 139
op, 
// 140
op, 
// 141
op, 
// 142
op, 
// 143
op, 
// 144
op, 
// 145
op, 
// 146
op, 
// 147
op, 
// 148
op, 
// 149
op, 
// 150
op, 
// 151
op, 
// 152
op, 
// 153
op, 
// 154
op, 
// 155
op, 
// 156
op, 
// 157
op, 
// 158
op, 
// 159
op, 
// 160
op, 
// 161
op, 
// 162
op, 
// 163
op, 
// 164
op, 
// 165
op, 
// 166
op, 
// 167
op, 
// 168
op, 
// 169
op, 
// 170
op, 
// 171
op, 
// 172
op, 
// 173
op, 
// 174
op, 
// 175
operation("XOR A", 1, 4, xorop), 
// 176
op, 
// 177
op, 
// 178
op, 
// 179
op, 
// 180
op, 
// 181
op, 
// 182
op, 
// 183
op, 
// 184
op, 
// 185
op, 
// 186
op, 
// 187
op, 
// 188
op, 
// 189
op, 
// 190
op, 
// 191
op, 
// 192
op, 
// 193
op, 
// 194
op, 
// 195
op, 
// 196
op, 
// 197
op, 
// 198
op, 
// 199
op, 
// 200
op, 
// 201
op, 
// 202
op, 
// 203
op, 
// 204
op, 
// 205
op, 
// 206
op, 
// 207
op, 
// 208
op, 
// 209
op, 
// 210
op, 
// 211
op, 
// 212
op, 
// 213
op, 
// 214
op, 
// 215
op, 
// 216
op, 
// 217
op, 
// 218
op, 
// 219
op, 
// 220
op, 
// 221
op, 
// 222
op, 
// 223
op, 
// 224
op, 
// 225
op, 
// 226
op, 
// 227
op, 
// 228
op, 
// 229
op, 
// 230
op, 
// 231
op, 
// 232
op, 
// 233
op, 
// 234
op, 
// 235
op, 
// 236
op, 
// 237
op, 
// 238
op, 
// 239
op, 
// 240
op, 
// 241
op, 
// 242
op, 
// 243
op, 
// 244
op, 
// 245
op, 
// 246
op, 
// 247
op, 
// 248
op, 
// 249
op, 
// 250
op, 
// 251
op, 
// 252
op, 
// 253
op, 
// 254
op, 
// 255
op, 
// 256
op, 
// 257
op, 
// 258
op, 
// 259
op, 
// 260
op, 
// 261
op, 
// 262
op, 
// 263
op, 
// 264
op, 
// 265
op, 
// 266
op, 
// 267
op, 
// 268
op, 
// 269
op, 
// 270
op, 
// 271
op, 
// 272
op, 
// 273
op, 
// 274
op, 
// 275
op, 
// 276
op, 
// 277
op, 
// 278
op, 
// 279
op, 
// 280
op, 
// 281
op, 
// 282
op, 
// 283
op, 
// 284
op, 
// 285
op, 
// 286
op, 
// 287
op, 
// 288
op, 
// 289
op, 
// 290
op, 
// 291
op, 
// 292
op, 
// 293
op, 
// 294
op, 
// 295
op, 
// 296
op, 
// 297
op, 
// 298
op, 
// 299
op, 
// 300
op, 
// 301
op, 
// 302
op, 
// 303
op, 
// 304
op, 
// 305
op, 
// 306
op, 
// 307
op, 
// 308
op, 
// 309
op, 
// 310
op, 
// 311
op, 
// 312
op, 
// 313
op, 
// 314
op, 
// 315
op, 
// 316
op, 
// 317
op, 
// 318
op, 
// 319
op, 
// 320
op, 
// 321
op, 
// 322
op, 
// 323
op, 
// 324
op, 
// 325
op, 
// 326
op, 
// 327
op, 
// 328
op, 
// 329
op, 
// 330
op, 
// 331
op, 
// 332
op, 
// 333
op, 
// 334
op, 
// 335
op, 
// 336
op, 
// 337
op, 
// 338
op, 
// 339
op, 
// 340
op, 
// 341
op, 
// 342
op, 
// 343
op, 
// 344
op, 
// 345
op, 
// 346
op, 
// 347
op, 
// 348
op, 
// 349
op, 
// 350
op, 
// 351
op, 
// 352
op, 
// 353
op, 
// 354
op, 
// 355
op, 
// 356
op, 
// 357
op, 
// 358
op, 
// 359
op, 
// 360
op, 
// 361
op, 
// 362
op, 
// 363
op, 
// 364
op, 
// 365
op, 
// 366
op, 
// 367
op, 
// 368
op, 
// 369
op, 
// 370
op, 
// 371
op, 
// 372
op, 
// 373
op, 
// 374
op, 
// 375
op, 
// 376
op, 
// 377
op, 
// 378
op, 
// 379
op, 
// 380
op, 
// 381
op, 
// 382
op, 
// 383
op, 
// 384
op, 
// 385
op, 
// 386
op, 
// 387
op, 
// 388
op, 
// 389
op, 
// 390
op, 
// 391
op, 
// 392
op, 
// 393
op, 
// 394
op, 
// 395
op, 
// 396
op, 
// 397
op, 
// 398
op, 
// 399
op, 
// 400
op, 
// 401
op, 
// 402
op, 
// 403
op, 
// 404
op, 
// 405
op, 
// 406
op, 
// 407
op, 
// 408
op, 
// 409
op, 
// 410
op, 
// 411
op, 
// 412
op, 
// 413
op, 
// 414
op, 
// 415
op, 
// 416
op, 
// 417
op, 
// 418
op, 
// 419
op, 
// 420
op, 
// 421
op, 
// 422
op, 
// 423
op, 
// 424
op, 
// 425
op, 
// 426
op, 
// 427
op, 
// 428
op, 
// 429
op, 
// 430
op, 
// 431
op, 
// 432
op, 
// 433
op, 
// 434
op, 
// 435
op, 
// 436
op, 
// 437
op, 
// 438
op, 
// 439
op, 
// 440
op, 
// 441
op, 
// 442
op, 
// 443
op, 
// 444
op, 
// 445
op, 
// 446
op, 
// 447
op, 
// 448
op, 
// 449
op, 
// 450
op, 
// 451
op, 
// 452
op, 
// 453
op, 
// 454
op, 
// 455
op, 
// 456
op, 
// 457
op, 
// 458
op, 
// 459
op, 
// 460
op, 
// 461
op, 
// 462
op, 
// 463
op, 
// 464
op, 
// 465
op, 
// 466
op, 
// 467
op, 
// 468
op, 
// 469
op, 
// 470
op, 
// 471
op, 
// 472
op, 
// 473
op, 
// 474
op, 
// 475
op, 
// 476
op, 
// 477
op, 
// 478
op, 
// 479
op, 
// 480
op, 
// 481
op, 
// 482
op, 
// 483
op, 
// 484
op, 
// 485
op, 
// 486
op, 
// 487
op, 
// 488
op, 
// 489
op, 
// 490
op, 
// 491
op, 
// 492
op, 
// 493
op, 
// 494
op, 
// 495
op, 
// 496
op, 
// 497
op, 
// 498
op, 
// 499
op, 
// 500
op, 
// 501
op, 
// 502
op, 
// 503
op, 
// 504
op, 
// 505
op, 
// 506
op, 
// 507
op, 
// 508
op, 
// 509
op, 
// 510
op, 
// 511
op, 

};


operation::operation(string name, int size, int cycles, bool (*f)(cpu*))
{
	this->name = name;
	this->size = size;
	this->cycles = cycles;
	func = f;
}
