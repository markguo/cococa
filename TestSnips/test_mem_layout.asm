
test_mem_layout:     file format elf64-x86-64

Disassembly of section .interp:

0000000000400200 <.interp>:
  400200:	2f                   	(bad)  
  400201:	6c                   	insb   (%dx),%es:(%rdi)
  400202:	69 62 36 34 2f 6c 64 	imul   $0x646c2f34,0x36(%rdx),%esp
  400209:	2d 6c 69 6e 75       	sub    $0x756e696c,%eax
  40020e:	78 2d                	js     40023d <_init-0x17b>
  400210:	78 38                	js     40024a <_init-0x16e>
  400212:	36                   	ss
  400213:	2d 36 34 2e 73       	sub    $0x732e3436,%eax
  400218:	6f                   	outsl  %ds:(%rsi),(%dx)
  400219:	2e 32 00             	xor    %cs:(%rax),%al
Disassembly of section .note.ABI-tag:

000000000040021c <.note.ABI-tag>:
  40021c:	04 00                	add    $0x0,%al
  40021e:	00 00                	add    %al,(%rax)
  400220:	10 00                	adc    %al,(%rax)
  400222:	00 00                	add    %al,(%rax)
  400224:	01 00                	add    %eax,(%rax)
  400226:	00 00                	add    %al,(%rax)
  400228:	47                   	rexXYZ
  400229:	4e 55                	rex64XY push   %rbp
  40022b:	00 00                	add    %al,(%rax)
  40022d:	00 00                	add    %al,(%rax)
  40022f:	00 02                	add    %al,(%rdx)
  400231:	00 00                	add    %al,(%rax)
  400233:	00 06                	add    %al,(%rsi)
  400235:	00 00                	add    %al,(%rax)
  400237:	00 09                	add    %cl,(%rcx)
  400239:	00 00                	add    %al,(%rax)
	...
Disassembly of section .gnu.hash:

0000000000400240 <.gnu.hash>:
  400240:	02 00                	add    (%rax),%al
  400242:	00 00                	add    %al,(%rax)
  400244:	04 00                	add    $0x0,%al
  400246:	00 00                	add    %al,(%rax)
  400248:	01 00                	add    %eax,(%rax)
  40024a:	00 00                	add    %al,(%rax)
  40024c:	06                   	(bad)  
  40024d:	00 00                	add    %al,(%rax)
  40024f:	00 00                	add    %al,(%rax)
  400251:	01 00                	add    %eax,(%rax)
  400253:	00 00                	add    %al,(%rax)
  400255:	00 00                	add    %al,(%rax)
  400257:	02 00                	add    (%rax),%al
  400259:	00 00                	add    %al,(%rax)
  40025b:	00 04 00             	add    %al,(%rax,%rax,1)
  40025e:	00 00                	add    %al,(%rax)
  400260:	39 f2                	cmp    %esi,%edx
  400262:	8b                   	.byte 0x8b
  400263:	1c                   	.byte 0x1c
Disassembly of section .dynsym:

0000000000400268 <.dynsym>:
	...
  400280:	01 00                	add    %eax,(%rax)
  400282:	00 00                	add    %al,(%rax)
  400284:	20 00                	and    %al,(%rax)
	...
  400296:	00 00                	add    %al,(%rax)
  400298:	29 00                	sub    %eax,(%rax)
  40029a:	00 00                	add    %al,(%rax)
  40029c:	12 00                	adc    (%rax),%al
	...
  4002a6:	00 00                	add    %al,(%rax)
  4002a8:	a5                   	movsl  %ds:(%rsi),%es:(%rdi)
  4002a9:	01 00                	add    %eax,(%rax)
  4002ab:	00 00                	add    %al,(%rax)
  4002ad:	00 00                	add    %al,(%rax)
  4002af:	00 21                	add    %ah,(%rcx)
  4002b1:	00 00                	add    %al,(%rax)
  4002b3:	00 12                	add    %dl,(%rdx)
	...
  4002bd:	00 00                	add    %al,(%rax)
  4002bf:	00 90 00 00 00 00    	add    %dl,0x0(%rax)
  4002c5:	00 00                	add    %al,(%rax)
  4002c7:	00 1a                	add    %bl,(%rdx)
  4002c9:	00 00                	add    %al,(%rax)
  4002cb:	00 11                	add    %dl,(%rcx)
  4002cd:	00 18                	add    %bl,(%rax)
  4002cf:	00 20                	add    %ah,(%rax)
  4002d1:	0a 60 00             	or     0x0(%rax),%ah
  4002d4:	00 00                	add    %al,(%rax)
  4002d6:	00 00                	add    %al,(%rax)
  4002d8:	08 00                	or     %al,(%rax)
  4002da:	00 00                	add    %al,(%rax)
  4002dc:	00 00                	add    %al,(%rax)
	...
Disassembly of section .dynstr:

00000000004002e0 <.dynstr>:
  4002e0:	00 5f 5f             	add    %bl,0x5f(%rdi)
  4002e3:	67 6d                	addr32 insl (%dx),%es:(%edi)
  4002e5:	6f                   	outsl  %ds:(%rsi),(%dx)
  4002e6:	6e                   	outsb  %ds:(%rsi),(%dx)
  4002e7:	5f                   	pop    %rdi
  4002e8:	73 74                	jae    40035e <_init-0x5a>
  4002ea:	61                   	(bad)  
  4002eb:	72 74                	jb     400361 <_init-0x57>
  4002ed:	5f                   	pop    %rdi
  4002ee:	5f                   	pop    %rdi
  4002ef:	00 6c 69 62          	add    %ch,0x62(%rcx,%rbp,2)
  4002f3:	63 2e                	movslq (%rsi),%ebp
  4002f5:	73 6f                	jae    400366 <_init-0x52>
  4002f7:	2e 36 00 73 74       	add    %dh,%cs:%ss:0x74(%rbx)
  4002fc:	64                   	fs
  4002fd:	65                   	gs
  4002fe:	72 72                	jb     400372 <_init-0x46>
  400300:	00 66 70             	add    %ah,0x70(%rsi)
  400303:	72 69                	jb     40036e <_init-0x4a>
  400305:	6e                   	outsb  %ds:(%rsi),(%dx)
  400306:	74 66                	je     40036e <_init-0x4a>
  400308:	00 5f 5f             	add    %bl,0x5f(%rdi)
  40030b:	6c                   	insb   (%dx),%es:(%rdi)
  40030c:	69 62 63 5f 73 74 61 	imul   $0x6174735f,0x63(%rdx),%esp
  400313:	72 74                	jb     400389 <_init-0x2f>
  400315:	5f                   	pop    %rdi
  400316:	6d                   	insl   (%dx),%es:(%rdi)
  400317:	61                   	(bad)  
  400318:	69 6e 00 47 4c 49 42 	imul   $0x42494c47,0x0(%rsi),%ebp
  40031f:	43 5f                	rexYZ pop    %r15
  400321:	32 2e                	xor    (%rsi),%ch
  400323:	32 2e                	xor    (%rsi),%ch
  400325:	35                   	.byte 0x35
	...
Disassembly of section .gnu.version:

0000000000400328 <.gnu.version>:
  400328:	00 00                	add    %al,(%rax)
  40032a:	00 00                	add    %al,(%rax)
  40032c:	02 00                	add    (%rax),%al
  40032e:	02 00                	add    (%rax),%al
  400330:	02 00                	add    (%rax),%al
Disassembly of section .gnu.version_r:

0000000000400338 <.gnu.version_r>:
  400338:	01 00                	add    %eax,(%rax)
  40033a:	01 00                	add    %eax,(%rax)
  40033c:	10 00                	adc    %al,(%rax)
  40033e:	00 00                	add    %al,(%rax)
  400340:	10 00                	adc    %al,(%rax)
  400342:	00 00                	add    %al,(%rax)
  400344:	00 00                	add    %al,(%rax)
  400346:	00 00                	add    %al,(%rax)
  400348:	75 1a                	jne    400364 <_init-0x54>
  40034a:	69 09 00 00 02 00    	imul   $0x20000,(%rcx),%ecx
  400350:	3b 00                	cmp    (%rax),%eax
  400352:	00 00                	add    %al,(%rax)
  400354:	00 00                	add    %al,(%rax)
	...
Disassembly of section .rela.dyn:

0000000000400358 <.rela.dyn>:
  400358:	e0 09                	loopne 400363 <_init-0x55>
  40035a:	60                   	(bad)  
  40035b:	00 00                	add    %al,(%rax)
  40035d:	00 00                	add    %al,(%rax)
  40035f:	00 06                	add    %al,(%rsi)
  400361:	00 00                	add    %al,(%rax)
  400363:	00 01                	add    %al,(%rcx)
	...
  40036d:	00 00                	add    %al,(%rax)
  40036f:	00 20                	add    %ah,(%rax)
  400371:	0a 60 00             	or     0x0(%rax),%ah
  400374:	00 00                	add    %al,(%rax)
  400376:	00 00                	add    %al,(%rax)
  400378:	05 00 00 00 04       	add    $0x4000000,%eax
	...
Disassembly of section .rela.plt:

0000000000400388 <.rela.plt>:
  400388:	00 0a                	add    %cl,(%rdx)
  40038a:	60                   	(bad)  
  40038b:	00 00                	add    %al,(%rax)
  40038d:	00 00                	add    %al,(%rax)
  40038f:	00 07                	add    %al,(%rdi)
  400391:	00 00                	add    %al,(%rax)
  400393:	00 02                	add    %al,(%rdx)
	...
  40039d:	00 00                	add    %al,(%rax)
  40039f:	00 08                	add    %cl,(%rax)
  4003a1:	0a 60 00             	or     0x0(%rax),%ah
  4003a4:	00 00                	add    %al,(%rax)
  4003a6:	00 00                	add    %al,(%rax)
  4003a8:	07                   	(bad)  
  4003a9:	00 00                	add    %al,(%rax)
  4003ab:	00 03                	add    %al,(%rbx)
	...
Disassembly of section .init:

00000000004003b8 <_init>:
  4003b8:	48 83 ec 08          	sub    $0x8,%rsp
  4003bc:	e8 6b 00 00 00       	callq  40042c <call_gmon_start>
  4003c1:	e8 ea 00 00 00       	callq  4004b0 <frame_dummy>
  4003c6:	e8 d5 02 00 00       	callq  4006a0 <__do_global_ctors_aux>
  4003cb:	48 83 c4 08          	add    $0x8,%rsp
  4003cf:	c3                   	retq   
Disassembly of section .plt:

00000000004003d0 <__libc_start_main@plt-0x10>:
  4003d0:	ff 35 1a 06 20 00    	pushq  2098714(%rip)        # 6009f0 <_GLOBAL_OFFSET_TABLE_+0x8>
  4003d6:	ff 25 1c 06 20 00    	jmpq   *2098716(%rip)        # 6009f8 <_GLOBAL_OFFSET_TABLE_+0x10>
  4003dc:	0f 1f 40 00          	nopl   0x0(%rax)

00000000004003e0 <__libc_start_main@plt>:
  4003e0:	ff 25 1a 06 20 00    	jmpq   *2098714(%rip)        # 600a00 <_GLOBAL_OFFSET_TABLE_+0x18>
  4003e6:	68 00 00 00 00       	pushq  $0x0
  4003eb:	e9 e0 ff ff ff       	jmpq   4003d0 <_init+0x18>

00000000004003f0 <fprintf@plt>:
  4003f0:	ff 25 12 06 20 00    	jmpq   *2098706(%rip)        # 600a08 <_GLOBAL_OFFSET_TABLE_+0x20>
  4003f6:	68 01 00 00 00       	pushq  $0x1
  4003fb:	e9 d0 ff ff ff       	jmpq   4003d0 <_init+0x18>
Disassembly of section .text:

0000000000400400 <_start>:
  400400:	31 ed                	xor    %ebp,%ebp
  400402:	49 89 d1             	mov    %rdx,%r9
  400405:	5e                   	pop    %rsi
  400406:	48 89 e2             	mov    %rsp,%rdx
  400409:	48 83 e4 f0          	and    $0xfffffffffffffff0,%rsp
  40040d:	50                   	push   %rax
  40040e:	54                   	push   %rsp
  40040f:	49 c7 c0 00 06 40 00 	mov    $0x400600,%r8
  400416:	48 c7 c1 10 06 40 00 	mov    $0x400610,%rcx
  40041d:	48 c7 c7 87 05 40 00 	mov    $0x400587,%rdi
  400424:	e8 b7 ff ff ff       	callq  4003e0 <__libc_start_main@plt>
  400429:	f4                   	hlt    
  40042a:	90                   	nop    
  40042b:	90                   	nop    

000000000040042c <call_gmon_start>:
  40042c:	48 83 ec 08          	sub    $0x8,%rsp
  400430:	48 8b 05 a9 05 20 00 	mov    2098601(%rip),%rax        # 6009e0 <_DYNAMIC+0x190>
  400437:	48 85 c0             	test   %rax,%rax
  40043a:	74 02                	je     40043e <call_gmon_start+0x12>
  40043c:	ff d0                	callq  *%rax
  40043e:	48 83 c4 08          	add    $0x8,%rsp
  400442:	c3                   	retq   
  400443:	90                   	nop    
  400444:	90                   	nop    
  400445:	90                   	nop    
  400446:	90                   	nop    
  400447:	90                   	nop    
  400448:	90                   	nop    
  400449:	90                   	nop    
  40044a:	90                   	nop    
  40044b:	90                   	nop    
  40044c:	90                   	nop    
  40044d:	90                   	nop    
  40044e:	90                   	nop    
  40044f:	90                   	nop    

0000000000400450 <__do_global_dtors_aux>:
  400450:	55                   	push   %rbp
  400451:	48 89 e5             	mov    %rsp,%rbp
  400454:	53                   	push   %rbx
  400455:	48 83 ec 08          	sub    $0x8,%rsp
  400459:	80 3d d0 05 20 00 00 	cmpb   $0x0,2098640(%rip)        # 600a30 <completed.6145>
  400460:	75 44                	jne    4004a6 <__do_global_dtors_aux+0x56>
  400462:	b8 40 08 60 00       	mov    $0x600840,%eax
  400467:	48 2d 38 08 60 00    	sub    $0x600838,%rax
  40046d:	48 c1 f8 03          	sar    $0x3,%rax
  400471:	48 8d 58 ff          	lea    0xffffffffffffffff(%rax),%rbx
  400475:	48 8b 05 ac 05 20 00 	mov    2098604(%rip),%rax        # 600a28 <dtor_idx.6147>
  40047c:	48 39 c3             	cmp    %rax,%rbx
  40047f:	76 1e                	jbe    40049f <__do_global_dtors_aux+0x4f>
  400481:	48 83 c0 01          	add    $0x1,%rax
  400485:	48 89 05 9c 05 20 00 	mov    %rax,2098588(%rip)        # 600a28 <dtor_idx.6147>
  40048c:	ff 14 c5 38 08 60 00 	callq  *0x600838(,%rax,8)
  400493:	48 8b 05 8e 05 20 00 	mov    2098574(%rip),%rax        # 600a28 <dtor_idx.6147>
  40049a:	48 39 c3             	cmp    %rax,%rbx
  40049d:	77 e2                	ja     400481 <__do_global_dtors_aux+0x31>
  40049f:	c6 05 8a 05 20 00 01 	movb   $0x1,2098570(%rip)        # 600a30 <completed.6145>
  4004a6:	48 83 c4 08          	add    $0x8,%rsp
  4004aa:	5b                   	pop    %rbx
  4004ab:	c9                   	leaveq 
  4004ac:	c3                   	retq   
  4004ad:	0f 1f 00             	nopl   (%rax)

00000000004004b0 <frame_dummy>:
  4004b0:	55                   	push   %rbp
  4004b1:	48 83 3d 8f 03 20 00 	cmpq   $0x0,2098063(%rip)        # 600848 <__JCR_END__>
  4004b8:	00 
  4004b9:	48 89 e5             	mov    %rsp,%rbp
  4004bc:	74 16                	je     4004d4 <frame_dummy+0x24>
  4004be:	b8 00 00 00 00       	mov    $0x0,%eax
  4004c3:	48 85 c0             	test   %rax,%rax
  4004c6:	74 0c                	je     4004d4 <frame_dummy+0x24>
  4004c8:	bf 48 08 60 00       	mov    $0x600848,%edi
  4004cd:	49 89 c3             	mov    %rax,%r11
  4004d0:	c9                   	leaveq 
  4004d1:	41 ff e3             	jmpq   *%r11
  4004d4:	c9                   	leaveq 
  4004d5:	c3                   	retq   
  4004d6:	90                   	nop    
  4004d7:	90                   	nop    

00000000004004d8 <bin2hex>:
  4004d8:	55                   	push   %rbp
  4004d9:	48 89 e5             	mov    %rsp,%rbp
  4004dc:	48 89 7d d8          	mov    %rdi,0xffffffffffffffd8(%rbp)
  4004e0:	48 89 75 d0          	mov    %rsi,0xffffffffffffffd0(%rbp)
  4004e4:	48 89 55 c8          	mov    %rdx,0xffffffffffffffc8(%rbp)
  4004e8:	48 89 4d c0          	mov    %rcx,0xffffffffffffffc0(%rbp)
  4004ec:	48 c7 45 e8 00 00 00 	movq   $0x0,0xffffffffffffffe8(%rbp)
  4004f3:	00 
  4004f4:	48 83 6d c0 01       	subq   $0x1,0xffffffffffffffc0(%rbp)
  4004f9:	48 c7 45 f0 00 00 00 	movq   $0x0,0xfffffffffffffff0(%rbp)
  400500:	00 
  400501:	eb 6a                	jmp    40056d <bin2hex+0x95>
  400503:	48 8b 45 f0          	mov    0xfffffffffffffff0(%rbp),%rax
  400507:	48 03 45 d8          	add    0xffffffffffffffd8(%rbp),%rax
  40050b:	0f b6 00             	movzbl (%rax),%eax
  40050e:	88 45 ff             	mov    %al,0xffffffffffffffff(%rbp)
  400511:	48 8b 45 e8          	mov    0xffffffffffffffe8(%rbp),%rax
  400515:	48 89 c1             	mov    %rax,%rcx
  400518:	48 03 4d c8          	add    0xffffffffffffffc8(%rbp),%rcx
  40051c:	0f b6 45 ff          	movzbl 0xffffffffffffffff(%rbp),%eax
  400520:	c0 e8 04             	shr    $0x4,%al
  400523:	0f b6 c0             	movzbl %al,%eax
  400526:	48 89 c2             	mov    %rax,%rdx
  400529:	48 8b 05 e8 04 20 00 	mov    2098408(%rip),%rax        # 600a18 <HexAlphabet>
  400530:	48 8d 04 02          	lea    (%rdx,%rax,1),%rax
  400534:	0f b6 00             	movzbl (%rax),%eax
  400537:	88 01                	mov    %al,(%rcx)
  400539:	48 8b 55 c8          	mov    0xffffffffffffffc8(%rbp),%rdx
  40053d:	48 83 c2 01          	add    $0x1,%rdx
  400541:	48 8b 45 e8          	mov    0xffffffffffffffe8(%rbp),%rax
  400545:	48 8d 0c 02          	lea    (%rdx,%rax,1),%rcx
  400549:	0f b6 45 ff          	movzbl 0xffffffffffffffff(%rbp),%eax
  40054d:	83 e0 0f             	and    $0xf,%eax
  400550:	48 89 c2             	mov    %rax,%rdx
  400553:	48 8b 05 be 04 20 00 	mov    2098366(%rip),%rax        # 600a18 <HexAlphabet>
  40055a:	48 8d 04 02          	lea    (%rdx,%rax,1),%rax
  40055e:	0f b6 00             	movzbl (%rax),%eax
  400561:	88 01                	mov    %al,(%rcx)
  400563:	48 83 45 e8 02       	addq   $0x2,0xffffffffffffffe8(%rbp)
  400568:	48 83 45 f0 01       	addq   $0x1,0xfffffffffffffff0(%rbp)
  40056d:	48 8b 45 f0          	mov    0xfffffffffffffff0(%rbp),%rax
  400571:	48 3b 45 d0          	cmp    0xffffffffffffffd0(%rbp),%rax
  400575:	73 0a                	jae    400581 <bin2hex+0xa9>
  400577:	48 8b 45 e8          	mov    0xffffffffffffffe8(%rbp),%rax
  40057b:	48 3b 45 c0          	cmp    0xffffffffffffffc0(%rbp),%rax
  40057f:	72 82                	jb     400503 <bin2hex+0x2b>
  400581:	48 8b 45 e8          	mov    0xffffffffffffffe8(%rbp),%rax
  400585:	c9                   	leaveq 
  400586:	c3                   	retq   

0000000000400587 <main>:
  400587:	55                   	push   %rbp
  400588:	48 89 e5             	mov    %rsp,%rbp
  40058b:	48 83 ec 10          	sub    $0x10,%rsp
  40058f:	0f b6 45 ff          	movzbl 0xffffffffffffffff(%rbp),%eax
  400593:	83 e0 c0             	and    $0xffffffffffffffc0,%eax
  400596:	83 c8 30             	or     $0x30,%eax
  400599:	88 45 ff             	mov    %al,0xffffffffffffffff(%rbp)
  40059c:	0f b6 45 ff          	movzbl 0xffffffffffffffff(%rbp),%eax
  4005a0:	83 c8 40             	or     $0x40,%eax
  4005a3:	88 45 ff             	mov    %al,0xffffffffffffffff(%rbp)
  4005a6:	0f b6 45 ff          	movzbl 0xffffffffffffffff(%rbp),%eax
  4005aa:	83 c8 80             	or     $0xffffffffffffff80,%eax
  4005ad:	88 45 ff             	mov    %al,0xffffffffffffffff(%rbp)
  4005b0:	0f b6 45 ff          	movzbl 0xffffffffffffffff(%rbp),%eax
  4005b4:	c0 e8 07             	shr    $0x7,%al
  4005b7:	0f b6 c8             	movzbl %al,%ecx
  4005ba:	0f b6 45 ff          	movzbl 0xffffffffffffffff(%rbp),%eax
  4005be:	c0 e8 06             	shr    $0x6,%al
  4005c1:	83 e0 01             	and    $0x1,%eax
  4005c4:	0f b6 f0             	movzbl %al,%esi
  4005c7:	0f b6 45 ff          	movzbl 0xffffffffffffffff(%rbp),%eax
  4005cb:	83 e0 3f             	and    $0x3f,%eax
  4005ce:	0f b6 d0             	movzbl %al,%edx
  4005d1:	48 8b 3d 48 04 20 00 	mov    2098248(%rip),%rdi        # 600a20 <__bss_start>
  4005d8:	41 b9 09 07 40 00    	mov    $0x400709,%r9d
  4005de:	41 89 c8             	mov    %ecx,%r8d
  4005e1:	89 f1                	mov    %esi,%ecx
  4005e3:	be 10 07 40 00       	mov    $0x400710,%esi
  4005e8:	b8 00 00 00 00       	mov    $0x0,%eax
  4005ed:	e8 fe fd ff ff       	callq  4003f0 <fprintf@plt>
  4005f2:	b8 00 00 00 00       	mov    $0x0,%eax
  4005f7:	c9                   	leaveq 
  4005f8:	c3                   	retq   
  4005f9:	90                   	nop    
  4005fa:	90                   	nop    
  4005fb:	90                   	nop    
  4005fc:	90                   	nop    
  4005fd:	90                   	nop    
  4005fe:	90                   	nop    
  4005ff:	90                   	nop    

0000000000400600 <__libc_csu_fini>:
  400600:	f3 c3                	repz retq 
  400602:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)
  400609:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)

0000000000400610 <__libc_csu_init>:
  400610:	4c 89 64 24 e0       	mov    %r12,0xffffffffffffffe0(%rsp)
  400615:	4c 89 6c 24 e8       	mov    %r13,0xffffffffffffffe8(%rsp)
  40061a:	4c 8d 25 03 02 20 00 	lea    2097667(%rip),%r12        # 600824 <__fini_array_end>
  400621:	4c 89 74 24 f0       	mov    %r14,0xfffffffffffffff0(%rsp)
  400626:	4c 89 7c 24 f8       	mov    %r15,0xfffffffffffffff8(%rsp)
  40062b:	49 89 f6             	mov    %rsi,%r14
  40062e:	48 89 5c 24 d0       	mov    %rbx,0xffffffffffffffd0(%rsp)
  400633:	48 89 6c 24 d8       	mov    %rbp,0xffffffffffffffd8(%rsp)
  400638:	48 83 ec 38          	sub    $0x38,%rsp
  40063c:	41 89 ff             	mov    %edi,%r15d
  40063f:	49 89 d5             	mov    %rdx,%r13
  400642:	e8 71 fd ff ff       	callq  4003b8 <_init>
  400647:	48 8d 05 d6 01 20 00 	lea    2097622(%rip),%rax        # 600824 <__fini_array_end>
  40064e:	49 29 c4             	sub    %rax,%r12
  400651:	49 c1 fc 03          	sar    $0x3,%r12
  400655:	4d 85 e4             	test   %r12,%r12
  400658:	74 1e                	je     400678 <__libc_csu_init+0x68>
  40065a:	31 ed                	xor    %ebp,%ebp
  40065c:	48 89 c3             	mov    %rax,%rbx
  40065f:	90                   	nop    
  400660:	48 83 c5 01          	add    $0x1,%rbp
  400664:	4c 89 ea             	mov    %r13,%rdx
  400667:	4c 89 f6             	mov    %r14,%rsi
  40066a:	44 89 ff             	mov    %r15d,%edi
  40066d:	ff 13                	callq  *(%rbx)
  40066f:	48 83 c3 08          	add    $0x8,%rbx
  400673:	49 39 ec             	cmp    %rbp,%r12
  400676:	75 e8                	jne    400660 <__libc_csu_init+0x50>
  400678:	48 8b 5c 24 08       	mov    0x8(%rsp),%rbx
  40067d:	48 8b 6c 24 10       	mov    0x10(%rsp),%rbp
  400682:	4c 8b 64 24 18       	mov    0x18(%rsp),%r12
  400687:	4c 8b 6c 24 20       	mov    0x20(%rsp),%r13
  40068c:	4c 8b 74 24 28       	mov    0x28(%rsp),%r14
  400691:	4c 8b 7c 24 30       	mov    0x30(%rsp),%r15
  400696:	48 83 c4 38          	add    $0x38,%rsp
  40069a:	c3                   	retq   
  40069b:	90                   	nop    
  40069c:	90                   	nop    
  40069d:	90                   	nop    
  40069e:	90                   	nop    
  40069f:	90                   	nop    

00000000004006a0 <__do_global_ctors_aux>:
  4006a0:	55                   	push   %rbp
  4006a1:	48 89 e5             	mov    %rsp,%rbp
  4006a4:	53                   	push   %rbx
  4006a5:	bb 28 08 60 00       	mov    $0x600828,%ebx
  4006aa:	48 83 ec 08          	sub    $0x8,%rsp
  4006ae:	48 8b 05 73 01 20 00 	mov    2097523(%rip),%rax        # 600828 <__CTOR_LIST__>
  4006b5:	48 83 f8 ff          	cmp    $0xffffffffffffffff,%rax
  4006b9:	74 14                	je     4006cf <__do_global_ctors_aux+0x2f>
  4006bb:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)
  4006c0:	48 83 eb 08          	sub    $0x8,%rbx
  4006c4:	ff d0                	callq  *%rax
  4006c6:	48 8b 03             	mov    (%rbx),%rax
  4006c9:	48 83 f8 ff          	cmp    $0xffffffffffffffff,%rax
  4006cd:	75 f1                	jne    4006c0 <__do_global_ctors_aux+0x20>
  4006cf:	48 83 c4 08          	add    $0x8,%rsp
  4006d3:	5b                   	pop    %rbx
  4006d4:	c9                   	leaveq 
  4006d5:	c3                   	retq   
  4006d6:	90                   	nop    
  4006d7:	90                   	nop    
Disassembly of section .fini:

00000000004006d8 <_fini>:
  4006d8:	48 83 ec 08          	sub    $0x8,%rsp
  4006dc:	e8 6f fd ff ff       	callq  400450 <__do_global_dtors_aux>
  4006e1:	48 83 c4 08          	add    $0x8,%rsp
  4006e5:	c3                   	retq   
Disassembly of section .rodata:

00000000004006e8 <_IO_stdin_used>:
  4006e8:	01 00                	add    %eax,(%rax)
  4006ea:	02 00                	add    (%rax),%al
  4006ec:	00 00                	add    %al,(%rax)
	...

00000000004006f0 <__dso_handle>:
	...
  4006f8:	30 31                	xor    %dh,(%rcx)
  4006fa:	32 33                	xor    (%rbx),%dh
  4006fc:	34 35                	xor    $0x35,%al
  4006fe:	36                   	ss
  4006ff:	37                   	(bad)  
  400700:	38 39                	cmp    %bh,(%rcx)
  400702:	41                   	rexZ
  400703:	42                   	rexY
  400704:	43                   	rexYZ
  400705:	44                   	rexX
  400706:	45                   	rexXZ
  400707:	46 00 00             	rexXY add    %r8b,(%rax)
  40070a:	00 00                	add    %al,(%rax)
  40070c:	00 00                	add    %al,(%rax)
  40070e:	00 00                	add    %al,(%rax)
  400710:	63 6c 69 65          	movslq 0x65(%rcx,%rbp,2),%ebp
  400714:	6e                   	outsb  %ds:(%rsi),(%dx)
  400715:	74 5f                	je     400776 <__dso_handle+0x86>
  400717:	69 64 3d 25 75 20 69 	imul   $0x6e692075,0x25(%rbp,%rdi,1),%esp
  40071e:	6e 
  40071f:	73 65                	jae    400786 <__dso_handle+0x96>
  400721:	72 74                	jb     400797 <__dso_handle+0xa7>
  400723:	5f                   	pop    %rdi
  400724:	68 6f 73 74 3d       	pushq  $0x3d74736f
  400729:	25 64 20 72 65       	and    $0x65722064,%eax
  40072e:	64 69 72 65 63 74 3d 	imul   $0x253d7463,%fs:0x65(%rdx),%esi
  400735:	25 
  400736:	64                   	fs
  400737:	2c 20                	sub    $0x20,%al
  400739:	68 65 78 3a 25       	pushq  $0x253a7865
  40073e:	73 0a                	jae    40074a <__dso_handle+0x5a>
	...
Disassembly of section .eh_frame_hdr:

0000000000400744 <.eh_frame_hdr>:
  400744:	01 1b                	add    %ebx,(%rbx)
  400746:	03 3b                	add    (%rbx),%edi
  400748:	28 00                	sub    %al,(%rax)
  40074a:	00 00                	add    %al,(%rax)
  40074c:	04 00                	add    $0x0,%al
  40074e:	00 00                	add    %al,(%rax)
  400750:	94                   	xchg   %eax,%esp
  400751:	fd                   	std    
  400752:	ff                   	(bad)  
  400753:	ff 44 00 00          	incl   0x0(%rax,%rax,1)
  400757:	00 43 fe             	add    %al,0xfffffffffffffffe(%rbx)
  40075a:	ff                   	(bad)  
  40075b:	ff 64 00 00          	jmpq   *0x0(%rax,%rax,1)
  40075f:	00 bc fe ff ff 9c 00 	add    %bh,0x9cffff(%rsi,%rdi,8)
  400766:	00 00                	add    %al,(%rax)
  400768:	cc                   	int3   
  400769:	fe                   	(bad)  
  40076a:	ff                   	(bad)  
  40076b:	ff                   	.byte 0xff
  40076c:	b4 00                	mov    $0x0,%ah
	...
Disassembly of section .eh_frame:

0000000000400770 <__FRAME_END__-0xb0>:
  400770:	14 00                	adc    $0x0,%al
  400772:	00 00                	add    %al,(%rax)
  400774:	00 00                	add    %al,(%rax)
  400776:	00 00                	add    %al,(%rax)
  400778:	01 7a 52             	add    %edi,0x52(%rdx)
  40077b:	00 01                	add    %al,(%rcx)
  40077d:	78 10                	js     40078f <__dso_handle+0x9f>
  40077f:	01 03                	add    %eax,(%rbx)
  400781:	0c 07                	or     $0x7,%al
  400783:	08 90 01 00 00 1c    	or     %dl,0x1c000001(%rax)
  400789:	00 00                	add    %al,(%rax)
  40078b:	00 1c 00             	add    %bl,(%rax,%rax,1)
  40078e:	00 00                	add    %al,(%rax)
  400790:	d8 04 40             	fadds  (%rax,%rax,2)
  400793:	00 af 00 00 00 00    	add    %ch,0x0(%rdi)
  400799:	41 0e                	rexZ (bad)  
  40079b:	10 86 02 43 0d 06    	adc    %al,0x60d4302(%rsi)
  4007a1:	00 00                	add    %al,(%rax)
  4007a3:	00 00                	add    %al,(%rax)
  4007a5:	00 00                	add    %al,(%rax)
  4007a7:	00 1c 00             	add    %bl,(%rax,%rax,1)
  4007aa:	00 00                	add    %al,(%rax)
  4007ac:	3c 00                	cmp    $0x0,%al
  4007ae:	00 00                	add    %al,(%rax)
  4007b0:	87 05 40 00 72 00    	xchg   %eax,7471168(%rip)        # b207f6 <_end+0x51fdbe>
  4007b6:	00 00                	add    %al,(%rax)
  4007b8:	00 41 0e             	add    %al,0xe(%rcx)
  4007bb:	10 86 02 43 0d 06    	adc    %al,0x60d4302(%rsi)
  4007c1:	00 00                	add    %al,(%rax)
  4007c3:	00 00                	add    %al,(%rax)
  4007c5:	00 00                	add    %al,(%rax)
  4007c7:	00 14 00             	add    %dl,(%rax,%rax,1)
  4007ca:	00 00                	add    %al,(%rax)
  4007cc:	00 00                	add    %al,(%rax)
  4007ce:	00 00                	add    %al,(%rax)
  4007d0:	01 7a 52             	add    %edi,0x52(%rdx)
  4007d3:	00 01                	add    %al,(%rcx)
  4007d5:	78 10                	js     4007e7 <__dso_handle+0xf7>
  4007d7:	01 1b                	add    %ebx,(%rbx)
  4007d9:	0c 07                	or     $0x7,%al
  4007db:	08 90 01 00 00 14    	or     %dl,0x14000001(%rax)
  4007e1:	00 00                	add    %al,(%rax)
  4007e3:	00 1c 00             	add    %bl,(%rax,%rax,1)
  4007e6:	00 00                	add    %al,(%rax)
  4007e8:	18 fe                	sbb    %bh,%dh
  4007ea:	ff                   	(bad)  
  4007eb:	ff 02                	incl   (%rdx)
	...
  4007f5:	00 00                	add    %al,(%rax)
  4007f7:	00 24 00             	add    %ah,(%rax,%rax,1)
  4007fa:	00 00                	add    %al,(%rax)
  4007fc:	34 00                	xor    $0x0,%al
  4007fe:	00 00                	add    %al,(%rax)
  400800:	10 fe                	adc    %bh,%dh
  400802:	ff                   	(bad)  
  400803:	ff 8b 00 00 00 00    	decl   0x0(%rbx)
  400809:	4a 8d 04 8c          	lea    (%rsp,%r9,4),%rax
  40080d:	05 51 8f 02 8e       	add    $0x8e028f51,%eax
  400812:	03 51 0e             	add    0xe(%rcx),%edx
  400815:	40 86 06             	xchg   %al,(%rsi)
  400818:	83 07 00             	addl   $0x0,(%rdi)
  40081b:	00 00                	add    %al,(%rax)
  40081d:	00 00                	add    %al,(%rax)
	...

0000000000400820 <__FRAME_END__>:
  400820:	00 00                	add    %al,(%rax)
	...
Disassembly of section .ctors:

0000000000600828 <__CTOR_LIST__>:
  600828:	ff                   	(bad)  
  600829:	ff                   	(bad)  
  60082a:	ff                   	(bad)  
  60082b:	ff                   	(bad)  
  60082c:	ff                   	(bad)  
  60082d:	ff                   	(bad)  
  60082e:	ff                   	(bad)  
  60082f:	ff 00                	incl   (%rax)

0000000000600830 <__CTOR_END__>:
	...
Disassembly of section .dtors:

0000000000600838 <__DTOR_LIST__>:
  600838:	ff                   	(bad)  
  600839:	ff                   	(bad)  
  60083a:	ff                   	(bad)  
  60083b:	ff                   	(bad)  
  60083c:	ff                   	(bad)  
  60083d:	ff                   	(bad)  
  60083e:	ff                   	(bad)  
  60083f:	ff 00                	incl   (%rax)

0000000000600840 <__DTOR_END__>:
	...
Disassembly of section .jcr:

0000000000600848 <__JCR_END__>:
	...
Disassembly of section .dynamic:

0000000000600850 <_DYNAMIC>:
  600850:	01 00                	add    %eax,(%rax)
  600852:	00 00                	add    %al,(%rax)
  600854:	00 00                	add    %al,(%rax)
  600856:	00 00                	add    %al,(%rax)
  600858:	10 00                	adc    %al,(%rax)
  60085a:	00 00                	add    %al,(%rax)
  60085c:	00 00                	add    %al,(%rax)
  60085e:	00 00                	add    %al,(%rax)
  600860:	0c 00                	or     $0x0,%al
  600862:	00 00                	add    %al,(%rax)
  600864:	00 00                	add    %al,(%rax)
  600866:	00 00                	add    %al,(%rax)
  600868:	b8 03 40 00 00       	mov    $0x4003,%eax
  60086d:	00 00                	add    %al,(%rax)
  60086f:	00 0d 00 00 00 00    	add    %cl,0(%rip)        # 600875 <_DYNAMIC+0x25>
  600875:	00 00                	add    %al,(%rax)
  600877:	00 d8                	add    %bl,%al
  600879:	06                   	(bad)  
  60087a:	40 00 00             	add    %al,(%rax)
  60087d:	00 00                	add    %al,(%rax)
  60087f:	00 f5                	add    %dh,%ch
  600881:	fe                   	(bad)  
  600882:	ff 6f 00             	ljmpq  *0x0(%rdi)
  600885:	00 00                	add    %al,(%rax)
  600887:	00 40 02             	add    %al,0x2(%rax)
  60088a:	40 00 00             	add    %al,(%rax)
  60088d:	00 00                	add    %al,(%rax)
  60088f:	00 05 00 00 00 00    	add    %al,0(%rip)        # 600895 <_DYNAMIC+0x45>
  600895:	00 00                	add    %al,(%rax)
  600897:	00 e0                	add    %ah,%al
  600899:	02 40 00             	add    0x0(%rax),%al
  60089c:	00 00                	add    %al,(%rax)
  60089e:	00 00                	add    %al,(%rax)
  6008a0:	06                   	(bad)  
  6008a1:	00 00                	add    %al,(%rax)
  6008a3:	00 00                	add    %al,(%rax)
  6008a5:	00 00                	add    %al,(%rax)
  6008a7:	00 68 02             	add    %ch,0x2(%rax)
  6008aa:	40 00 00             	add    %al,(%rax)
  6008ad:	00 00                	add    %al,(%rax)
  6008af:	00 0a                	add    %cl,(%rdx)
  6008b1:	00 00                	add    %al,(%rax)
  6008b3:	00 00                	add    %al,(%rax)
  6008b5:	00 00                	add    %al,(%rax)
  6008b7:	00 47 00             	add    %al,0x0(%rdi)
  6008ba:	00 00                	add    %al,(%rax)
  6008bc:	00 00                	add    %al,(%rax)
  6008be:	00 00                	add    %al,(%rax)
  6008c0:	0b 00                	or     (%rax),%eax
  6008c2:	00 00                	add    %al,(%rax)
  6008c4:	00 00                	add    %al,(%rax)
  6008c6:	00 00                	add    %al,(%rax)
  6008c8:	18 00                	sbb    %al,(%rax)
  6008ca:	00 00                	add    %al,(%rax)
  6008cc:	00 00                	add    %al,(%rax)
  6008ce:	00 00                	add    %al,(%rax)
  6008d0:	15 00 00 00 00       	adc    $0x0,%eax
	...
  6008dd:	00 00                	add    %al,(%rax)
  6008df:	00 03                	add    %al,(%rbx)
  6008e1:	00 00                	add    %al,(%rax)
  6008e3:	00 00                	add    %al,(%rax)
  6008e5:	00 00                	add    %al,(%rax)
  6008e7:	00 e8                	add    %ch,%al
  6008e9:	09 60 00             	or     %esp,0x0(%rax)
  6008ec:	00 00                	add    %al,(%rax)
  6008ee:	00 00                	add    %al,(%rax)
  6008f0:	02 00                	add    (%rax),%al
  6008f2:	00 00                	add    %al,(%rax)
  6008f4:	00 00                	add    %al,(%rax)
  6008f6:	00 00                	add    %al,(%rax)
  6008f8:	30 00                	xor    %al,(%rax)
  6008fa:	00 00                	add    %al,(%rax)
  6008fc:	00 00                	add    %al,(%rax)
  6008fe:	00 00                	add    %al,(%rax)
  600900:	14 00                	adc    $0x0,%al
  600902:	00 00                	add    %al,(%rax)
  600904:	00 00                	add    %al,(%rax)
  600906:	00 00                	add    %al,(%rax)
  600908:	07                   	(bad)  
  600909:	00 00                	add    %al,(%rax)
  60090b:	00 00                	add    %al,(%rax)
  60090d:	00 00                	add    %al,(%rax)
  60090f:	00 17                	add    %dl,(%rdi)
  600911:	00 00                	add    %al,(%rax)
  600913:	00 00                	add    %al,(%rax)
  600915:	00 00                	add    %al,(%rax)
  600917:	00 88 03 40 00 00    	add    %cl,0x4003(%rax)
  60091d:	00 00                	add    %al,(%rax)
  60091f:	00 07                	add    %al,(%rdi)
  600921:	00 00                	add    %al,(%rax)
  600923:	00 00                	add    %al,(%rax)
  600925:	00 00                	add    %al,(%rax)
  600927:	00 58 03             	add    %bl,0x3(%rax)
  60092a:	40 00 00             	add    %al,(%rax)
  60092d:	00 00                	add    %al,(%rax)
  60092f:	00 08                	add    %cl,(%rax)
  600931:	00 00                	add    %al,(%rax)
  600933:	00 00                	add    %al,(%rax)
  600935:	00 00                	add    %al,(%rax)
  600937:	00 30                	add    %dh,(%rax)
  600939:	00 00                	add    %al,(%rax)
  60093b:	00 00                	add    %al,(%rax)
  60093d:	00 00                	add    %al,(%rax)
  60093f:	00 09                	add    %cl,(%rcx)
  600941:	00 00                	add    %al,(%rax)
  600943:	00 00                	add    %al,(%rax)
  600945:	00 00                	add    %al,(%rax)
  600947:	00 18                	add    %bl,(%rax)
  600949:	00 00                	add    %al,(%rax)
  60094b:	00 00                	add    %al,(%rax)
  60094d:	00 00                	add    %al,(%rax)
  60094f:	00 fe                	add    %bh,%dh
  600951:	ff                   	(bad)  
  600952:	ff 6f 00             	ljmpq  *0x0(%rdi)
  600955:	00 00                	add    %al,(%rax)
  600957:	00 38                	add    %bh,(%rax)
  600959:	03 40 00             	add    0x0(%rax),%eax
  60095c:	00 00                	add    %al,(%rax)
  60095e:	00 00                	add    %al,(%rax)
  600960:	ff                   	(bad)  
  600961:	ff                   	(bad)  
  600962:	ff 6f 00             	ljmpq  *0x0(%rdi)
  600965:	00 00                	add    %al,(%rax)
  600967:	00 01                	add    %al,(%rcx)
  600969:	00 00                	add    %al,(%rax)
  60096b:	00 00                	add    %al,(%rax)
  60096d:	00 00                	add    %al,(%rax)
  60096f:	00 f0                	add    %dh,%al
  600971:	ff                   	(bad)  
  600972:	ff 6f 00             	ljmpq  *0x0(%rdi)
  600975:	00 00                	add    %al,(%rax)
  600977:	00 28                	add    %ch,(%rax)
  600979:	03 40 00             	add    0x0(%rax),%eax
	...
Disassembly of section .got:

00000000006009e0 <.got>:
	...
Disassembly of section .got.plt:

00000000006009e8 <_GLOBAL_OFFSET_TABLE_>:
  6009e8:	50                   	push   %rax
  6009e9:	08 60 00             	or     %ah,0x0(%rax)
	...
  600a00:	e6 03                	out    %al,$0x3
  600a02:	40 00 00             	add    %al,(%rax)
  600a05:	00 00                	add    %al,(%rax)
  600a07:	00 f6                	add    %dh,%dh
  600a09:	03 40 00             	add    0x0(%rax),%eax
  600a0c:	00 00                	add    %al,(%rax)
	...
Disassembly of section .data:

0000000000600a10 <__data_start>:
	...

0000000000600a18 <HexAlphabet>:
  600a18:	f8                   	clc    
  600a19:	06                   	(bad)  
  600a1a:	40 00 00             	add    %al,(%rax)
  600a1d:	00 00                	add    %al,(%rax)
	...
Disassembly of section .bss:

0000000000600a20 <stderr@@GLIBC_2.2.5>:
	...

0000000000600a28 <dtor_idx.6147>:
	...

0000000000600a30 <completed.6145>:
	...
Disassembly of section .comment:

0000000000000000 <.comment>:
   0:	00 47 43             	add    %al,0x43(%rdi)
   3:	43 3a 20             	rexYZ cmp    (%r8),%spl
   6:	28 47 4e             	sub    %al,0x4e(%rdi)
   9:	55                   	push   %rbp
   a:	29 20                	sub    %esp,(%rax)
   c:	34 2e                	xor    $0x2e,%al
   e:	31 2e                	xor    %ebp,(%rsi)
  10:	32 20                	xor    (%rax),%ah
  12:	32 30                	xor    (%rax),%dh
  14:	30 38                	xor    %bh,(%rax)
  16:	30 37                	xor    %dh,(%rdi)
  18:	30 34 20             	xor    %dh,(%rax)
  1b:	28 52 65             	sub    %dl,0x65(%rdx)
  1e:	64 20 48 61          	and    %cl,%fs:0x61(%rax)
  22:	74 20                	je     44 <_init-0x400374>
  24:	34 2e                	xor    $0x2e,%al
  26:	31 2e                	xor    %ebp,(%rsi)
  28:	32 2d 34 34 29 00    	xor    2700340(%rip),%ch        # 293462 <_init-0x16cf56>
  2e:	00 47 43             	add    %al,0x43(%rdi)
  31:	43 3a 20             	rexYZ cmp    (%r8),%spl
  34:	28 47 4e             	sub    %al,0x4e(%rdi)
  37:	55                   	push   %rbp
  38:	29 20                	sub    %esp,(%rax)
  3a:	34 2e                	xor    $0x2e,%al
  3c:	31 2e                	xor    %ebp,(%rsi)
  3e:	32 20                	xor    (%rax),%ah
  40:	32 30                	xor    (%rax),%dh
  42:	30 38                	xor    %bh,(%rax)
  44:	30 37                	xor    %dh,(%rdi)
  46:	30 34 20             	xor    %dh,(%rax)
  49:	28 52 65             	sub    %dl,0x65(%rdx)
  4c:	64 20 48 61          	and    %cl,%fs:0x61(%rax)
  50:	74 20                	je     72 <_init-0x400346>
  52:	34 2e                	xor    $0x2e,%al
  54:	31 2e                	xor    %ebp,(%rsi)
  56:	32 2d 34 34 29 00    	xor    2700340(%rip),%ch        # 293490 <_init-0x16cf28>
  5c:	00 47 43             	add    %al,0x43(%rdi)
  5f:	43 3a 20             	rexYZ cmp    (%r8),%spl
  62:	28 47 4e             	sub    %al,0x4e(%rdi)
  65:	55                   	push   %rbp
  66:	29 20                	sub    %esp,(%rax)
  68:	34 2e                	xor    $0x2e,%al
  6a:	31 2e                	xor    %ebp,(%rsi)
  6c:	32 20                	xor    (%rax),%ah
  6e:	32 30                	xor    (%rax),%dh
  70:	30 38                	xor    %bh,(%rax)
  72:	30 37                	xor    %dh,(%rdi)
  74:	30 34 20             	xor    %dh,(%rax)
  77:	28 52 65             	sub    %dl,0x65(%rdx)
  7a:	64 20 48 61          	and    %cl,%fs:0x61(%rax)
  7e:	74 20                	je     a0 <_init-0x400318>
  80:	34 2e                	xor    $0x2e,%al
  82:	31 2e                	xor    %ebp,(%rsi)
  84:	32 2d 34 34 29 00    	xor    2700340(%rip),%ch        # 2934be <_init-0x16cefa>
  8a:	00 47 43             	add    %al,0x43(%rdi)
  8d:	43 3a 20             	rexYZ cmp    (%r8),%spl
  90:	28 47 4e             	sub    %al,0x4e(%rdi)
  93:	55                   	push   %rbp
  94:	29 20                	sub    %esp,(%rax)
  96:	34 2e                	xor    $0x2e,%al
  98:	31 2e                	xor    %ebp,(%rsi)
  9a:	32 20                	xor    (%rax),%ah
  9c:	32 30                	xor    (%rax),%dh
  9e:	30 38                	xor    %bh,(%rax)
  a0:	30 37                	xor    %dh,(%rdi)
  a2:	30 34 20             	xor    %dh,(%rax)
  a5:	28 52 65             	sub    %dl,0x65(%rdx)
  a8:	64 20 48 61          	and    %cl,%fs:0x61(%rax)
  ac:	74 20                	je     ce <_init-0x4002ea>
  ae:	34 2e                	xor    $0x2e,%al
  b0:	31 2e                	xor    %ebp,(%rsi)
  b2:	32 2d 34 34 29 00    	xor    2700340(%rip),%ch        # 2934ec <_init-0x16cecc>
  b8:	00 47 43             	add    %al,0x43(%rdi)
  bb:	43 3a 20             	rexYZ cmp    (%r8),%spl
  be:	28 47 4e             	sub    %al,0x4e(%rdi)
  c1:	55                   	push   %rbp
  c2:	29 20                	sub    %esp,(%rax)
  c4:	34 2e                	xor    $0x2e,%al
  c6:	31 2e                	xor    %ebp,(%rsi)
  c8:	32 20                	xor    (%rax),%ah
  ca:	32 30                	xor    (%rax),%dh
  cc:	30 38                	xor    %bh,(%rax)
  ce:	30 37                	xor    %dh,(%rdi)
  d0:	30 34 20             	xor    %dh,(%rax)
  d3:	28 52 65             	sub    %dl,0x65(%rdx)
  d6:	64 20 48 61          	and    %cl,%fs:0x61(%rax)
  da:	74 20                	je     fc <_init-0x4002bc>
  dc:	34 2e                	xor    $0x2e,%al
  de:	31 2e                	xor    %ebp,(%rsi)
  e0:	32 2d 34 34 29 00    	xor    2700340(%rip),%ch        # 29351a <_init-0x16ce9e>
  e6:	00 47 43             	add    %al,0x43(%rdi)
  e9:	43 3a 20             	rexYZ cmp    (%r8),%spl
  ec:	28 47 4e             	sub    %al,0x4e(%rdi)
  ef:	55                   	push   %rbp
  f0:	29 20                	sub    %esp,(%rax)
  f2:	34 2e                	xor    $0x2e,%al
  f4:	31 2e                	xor    %ebp,(%rsi)
  f6:	32 20                	xor    (%rax),%ah
  f8:	32 30                	xor    (%rax),%dh
  fa:	30 38                	xor    %bh,(%rax)
  fc:	30 37                	xor    %dh,(%rdi)
  fe:	30 34 20             	xor    %dh,(%rax)
 101:	28 52 65             	sub    %dl,0x65(%rdx)
 104:	64 20 48 61          	and    %cl,%fs:0x61(%rax)
 108:	74 20                	je     12a <_init-0x40028e>
 10a:	34 2e                	xor    $0x2e,%al
 10c:	31 2e                	xor    %ebp,(%rsi)
 10e:	32 2d 34 34 29 00    	xor    2700340(%rip),%ch        # 293548 <_init-0x16ce70>
Disassembly of section .debug_aranges:

0000000000000000 <.debug_aranges>:
   0:	2c 00                	sub    $0x0,%al
   2:	00 00                	add    %al,(%rax)
   4:	02 00                	add    (%rax),%al
   6:	00 00                	add    %al,(%rax)
   8:	00 00                	add    %al,(%rax)
   a:	08 00                	or     %al,(%rax)
   c:	00 00                	add    %al,(%rax)
   e:	00 00                	add    %al,(%rax)
  10:	d8 04 40             	fadds  (%rax,%rax,2)
  13:	00 00                	add    %al,(%rax)
  15:	00 00                	add    %al,(%rax)
  17:	00 21                	add    %ah,(%rcx)
  19:	01 00                	add    %eax,(%rax)
	...
Disassembly of section .debug_pubnames:

0000000000000000 <.debug_pubnames>:
   0:	23 00                	and    (%rax),%eax
   2:	00 00                	add    %al,(%rax)
   4:	02 00                	add    (%rax),%al
   6:	00 00                	add    %al,(%rax)
   8:	00 00                	add    %al,(%rax)
   a:	cc                   	int3   
   b:	05 00 00 b4 04       	add    $0x4b40000,%eax
  10:	00 00                	add    %al,(%rax)
  12:	62                   	(bad)  
  13:	69 6e 32 68 65 78 00 	imul   $0x786568,0x32(%rsi),%ebp
  1a:	6a 05                	pushq  $0x5
  1c:	00 00                	add    %al,(%rax)
  1e:	6d                   	insl   (%dx),%es:(%rdi)
  1f:	61                   	(bad)  
  20:	69 6e 00 00 00 00 00 	imul   $0x0,0x0(%rsi),%ebp
Disassembly of section .debug_info:

0000000000000000 <.debug_info>:
   0:	c8 05 00 00          	enterq $0x5,$0x0
   4:	02 00                	add    (%rax),%al
   6:	00 00                	add    %al,(%rax)
   8:	00 00                	add    %al,(%rax)
   a:	08 01                	or     %al,(%rcx)
   c:	00 00                	add    %al,(%rax)
   e:	00 00                	add    %al,(%rax)
  10:	f9                   	stc    
  11:	05 40 00 00 00       	add    $0x40,%eax
  16:	00 00                	add    %al,(%rax)
  18:	d8 04 40             	fadds  (%rax,%rax,2)
  1b:	00 00                	add    %al,(%rax)
  1d:	00 00                	add    %al,(%rax)
  1f:	00 47 4e             	add    %al,0x4e(%rdi)
  22:	55                   	push   %rbp
  23:	20 43 20             	and    %al,0x20(%rbx)
  26:	34 2e                	xor    $0x2e,%al
  28:	31 2e                	xor    %ebp,(%rsi)
  2a:	32 20                	xor    (%rax),%ah
  2c:	32 30                	xor    (%rax),%dh
  2e:	30 38                	xor    %bh,(%rax)
  30:	30 37                	xor    %dh,(%rdi)
  32:	30 34 20             	xor    %dh,(%rax)
  35:	28 52 65             	sub    %dl,0x65(%rdx)
  38:	64 20 48 61          	and    %cl,%fs:0x61(%rax)
  3c:	74 20                	je     5e <_init-0x40035a>
  3e:	34 2e                	xor    $0x2e,%al
  40:	31 2e                	xor    %ebp,(%rsi)
  42:	32 2d 34 34 29 00    	xor    2700340(%rip),%ch        # 29347c <_init-0x16cf3c>
  48:	01 74 65 73          	add    %esi,0x73(%rbp,2)
  4c:	74 5f                	je     ad <_init-0x40030b>
  4e:	6d                   	insl   (%dx),%es:(%rdi)
  4f:	65                   	gs
  50:	6d                   	insl   (%dx),%es:(%rdi)
  51:	5f                   	pop    %rdi
  52:	6c                   	insb   (%dx),%es:(%rdi)
  53:	61                   	(bad)  
  54:	79 6f                	jns    c5 <_init-0x4002f3>
  56:	75 74                	jne    cc <_init-0x4002ec>
  58:	2e 63 00             	movslq %cs:(%rax),%eax
  5b:	2f                   	(bad)  
  5c:	68 6f 6d 65 2f       	pushq  $0x2f656d6f
  61:	67 75 6f             	addr32 jne d3 <_init-0x4002e5>
  64:	73 68                	jae    ce <_init-0x4002ea>
  66:	69 77 65 69 2f 64 65 	imul   $0x65642f69,0x65(%rdi),%esi
  6d:	76 65                	jbe    d4 <_init-0x4002e4>
  6f:	6c                   	insb   (%dx),%es:(%rdi)
  70:	6f                   	outsl  %ds:(%rsi),(%dx)
  71:	70 6d                	jo     e0 <_init-0x4002d8>
  73:	65 6e                	outsb  %gs:(%rsi),(%dx)
  75:	74 2f                	je     a6 <_init-0x400312>
  77:	74 65                	je     de <_init-0x4002da>
  79:	6d                   	insl   (%dx),%es:(%rdi)
  7a:	70 5f                	jo     db <_init-0x4002dd>
  7c:	63 6f 64             	movslq 0x64(%rdi),%ebp
  7f:	65                   	gs
  80:	73 2f                	jae    b1 <_init-0x400307>
  82:	74 65                	je     e9 <_init-0x4002cf>
  84:	73 74                	jae    fa <_init-0x4002be>
  86:	5f                   	pop    %rdi
  87:	63 5f 73             	movslq 0x73(%rdi),%ebx
  8a:	72 63                	jb     ef <_init-0x4002c9>
  8c:	00 02                	add    %al,(%rdx)
  8e:	73 69                	jae    f9 <_init-0x4002bf>
  90:	7a 65                	jp     f7 <_init-0x4002c1>
  92:	5f                   	pop    %rdi
  93:	74 00                	je     95 <_init-0x400323>
  95:	02 d6                	add    %dh,%dl
  97:	9b                   	fwait
  98:	00 00                	add    %al,(%rax)
  9a:	00 03                	add    %al,(%rbx)
  9c:	00 00                	add    %al,(%rax)
  9e:	00 00                	add    %al,(%rax)
  a0:	08 07                	or     %al,(%rdi)
  a2:	04 75                	add    $0x75,%al
  a4:	6e                   	outsb  %ds:(%rsi),(%dx)
  a5:	73 69                	jae    110 <_init-0x4002a8>
  a7:	67 6e                	addr32 outsb %ds:(%esi),(%dx)
  a9:	65 64 20 63 68       	and    %ah,%fs:%gs:0x68(%rbx)
  ae:	61                   	(bad)  
  af:	72 00                	jb     b1 <_init-0x400307>
  b1:	01 08                	add    %ecx,(%rax)
  b3:	04 73                	add    $0x73,%al
  b5:	68 6f 72 74 20       	pushq  $0x2074726f
  ba:	75 6e                	jne    12a <_init-0x40028e>
  bc:	73 69                	jae    127 <_init-0x400291>
  be:	67 6e                	addr32 outsb %ds:(%esi),(%dx)
  c0:	65 64 20 69 6e       	and    %ch,%fs:%gs:0x6e(%rcx)
  c5:	74 00                	je     c7 <_init-0x4002f1>
  c7:	02 07                	add    (%rdi),%al
  c9:	04 75                	add    $0x75,%al
  cb:	6e                   	outsb  %ds:(%rsi),(%dx)
  cc:	73 69                	jae    137 <_init-0x400281>
  ce:	67 6e                	addr32 outsb %ds:(%esi),(%dx)
  d0:	65 64 20 69 6e       	and    %ch,%fs:%gs:0x6e(%rcx)
  d5:	74 00                	je     d7 <_init-0x4002e1>
  d7:	04 07                	add    $0x7,%al
  d9:	04 73                	add    $0x73,%al
  db:	69 67 6e 65 64 20 63 	imul   $0x63206465,0x6e(%rdi),%esp
  e2:	68 61 72 00 01       	pushq  $0x1007261
  e7:	06                   	(bad)  
  e8:	04 73                	add    $0x73,%al
  ea:	68 6f 72 74 20       	pushq  $0x2074726f
  ef:	69 6e 74 00 02 05 04 	imul   $0x4050200,0x74(%rsi),%ebp
  f6:	69 6e 74 00 04 05 04 	imul   $0x4050400,0x74(%rsi),%ebp
  fd:	6c                   	insb   (%dx),%es:(%rdi)
  fe:	6f                   	outsl  %ds:(%rsi),(%dx)
  ff:	6e                   	outsb  %ds:(%rsi),(%dx)
 100:	67 20 69 6e          	addr32 and %ch,0x6e(%ecx)
 104:	74 00                	je     106 <_init-0x4002b2>
 106:	08 05 02 5f 5f 6f    	or     %al,1868521218(%rip)        # 6f5f600e <_end+0x6eff55d6>
 10c:	66 66 5f             	pop    %di
 10f:	74 00                	je     111 <_init-0x4002a7>
 111:	05 90 fc 00 00       	add    $0xfc90,%eax
 116:	00 02                	add    %al,(%rdx)
 118:	5f                   	pop    %rdi
 119:	5f                   	pop    %rdi
 11a:	6f                   	outsl  %ds:(%rsi),(%dx)
 11b:	66                   	data16
 11c:	66                   	data16
 11d:	36                   	ss
 11e:	34 5f                	xor    $0x5f,%al
 120:	74 00                	je     122 <_init-0x400296>
 122:	05 91 fc 00 00       	add    $0xfc91,%eax
 127:	00 03                	add    %al,(%rbx)
 129:	00 00                	add    %al,(%rax)
 12b:	00 00                	add    %al,(%rax)
 12d:	08 07                	or     %al,(%rdi)
 12f:	05 08 06 08 37       	add    $0x37080608,%eax
 134:	01 00                	add    %eax,(%rax)
 136:	00 04 63             	add    %al,(%rbx,2)
 139:	68 61 72 00 01       	pushq  $0x1007261
 13e:	06                   	(bad)  
 13f:	07                   	(bad)  
 140:	c6 03 00             	movb   $0x0,(%rbx)
 143:	00 12                	add    %dl,(%rdx)
 145:	00 00                	add    %al,(%rax)
 147:	00 d8                	add    %bl,%al
 149:	03 2e                	add    (%rsi),%ebp
 14b:	08 5f 66             	or     %bl,0x66(%rdi)
 14e:	6c                   	insb   (%dx),%es:(%rdi)
 14f:	61                   	(bad)  
 150:	67 73 00             	addr32 jae 153 <_init-0x400265>
 153:	04 0d                	add    $0xd,%al
 155:	01 f5                	add    %esi,%ebp
 157:	00 00                	add    %al,(%rax)
 159:	00 02                	add    %al,(%rdx)
 15b:	23 00                	and    (%rax),%eax
 15d:	08 5f 49             	or     %bl,0x49(%rdi)
 160:	4f 5f                	rex64XYZ pop    %r15
 162:	72 65                	jb     1c9 <_init-0x4001ef>
 164:	61                   	(bad)  
 165:	64                   	fs
 166:	5f                   	pop    %rdi
 167:	70 74                	jo     1dd <_init-0x4001db>
 169:	72 00                	jb     16b <_init-0x40024d>
 16b:	04 12                	add    $0x12,%al
 16d:	01 31                	add    %esi,(%rcx)
 16f:	01 00                	add    %eax,(%rax)
 171:	00 02                	add    %al,(%rdx)
 173:	23 08                	and    (%rax),%ecx
 175:	08 5f 49             	or     %bl,0x49(%rdi)
 178:	4f 5f                	rex64XYZ pop    %r15
 17a:	72 65                	jb     1e1 <_init-0x4001d7>
 17c:	61                   	(bad)  
 17d:	64                   	fs
 17e:	5f                   	pop    %rdi
 17f:	65 6e                	outsb  %gs:(%rsi),(%dx)
 181:	64 00 04 13          	add    %al,%fs:(%rbx,%rdx,1)
 185:	01 31                	add    %esi,(%rcx)
 187:	01 00                	add    %eax,(%rax)
 189:	00 02                	add    %al,(%rdx)
 18b:	23 10                	and    (%rax),%edx
 18d:	08 5f 49             	or     %bl,0x49(%rdi)
 190:	4f 5f                	rex64XYZ pop    %r15
 192:	72 65                	jb     1f9 <_init-0x4001bf>
 194:	61                   	(bad)  
 195:	64                   	fs
 196:	5f                   	pop    %rdi
 197:	62                   	(bad)  
 198:	61                   	(bad)  
 199:	73 65                	jae    200 <_init-0x4001b8>
 19b:	00 04 14             	add    %al,(%rsp,%rdx,1)
 19e:	01 31                	add    %esi,(%rcx)
 1a0:	01 00                	add    %eax,(%rax)
 1a2:	00 02                	add    %al,(%rdx)
 1a4:	23 18                	and    (%rax),%ebx
 1a6:	08 5f 49             	or     %bl,0x49(%rdi)
 1a9:	4f 5f                	rex64XYZ pop    %r15
 1ab:	77 72                	ja     21f <_init-0x400199>
 1ad:	69 74 65 5f 62 61 73 	imul   $0x65736162,0x5f(%rbp,2),%esi
 1b4:	65 
 1b5:	00 04 15 01 31 01 00 	add    %al,0x13101(,%rdx,1)
 1bc:	00 02                	add    %al,(%rdx)
 1be:	23 20                	and    (%rax),%esp
 1c0:	08 5f 49             	or     %bl,0x49(%rdi)
 1c3:	4f 5f                	rex64XYZ pop    %r15
 1c5:	77 72                	ja     239 <_init-0x40017f>
 1c7:	69 74 65 5f 70 74 72 	imul   $0x727470,0x5f(%rbp,2),%esi
 1ce:	00 
 1cf:	04 16                	add    $0x16,%al
 1d1:	01 31                	add    %esi,(%rcx)
 1d3:	01 00                	add    %eax,(%rax)
 1d5:	00 02                	add    %al,(%rdx)
 1d7:	23 28                	and    (%rax),%ebp
 1d9:	08 5f 49             	or     %bl,0x49(%rdi)
 1dc:	4f 5f                	rex64XYZ pop    %r15
 1de:	77 72                	ja     252 <_init-0x400166>
 1e0:	69 74 65 5f 65 6e 64 	imul   $0x646e65,0x5f(%rbp,2),%esi
 1e7:	00 
 1e8:	04 17                	add    $0x17,%al
 1ea:	01 31                	add    %esi,(%rcx)
 1ec:	01 00                	add    %eax,(%rax)
 1ee:	00 02                	add    %al,(%rdx)
 1f0:	23 30                	and    (%rax),%esi
 1f2:	08 5f 49             	or     %bl,0x49(%rdi)
 1f5:	4f 5f                	rex64XYZ pop    %r15
 1f7:	62                   	(bad)  
 1f8:	75 66                	jne    260 <_init-0x400158>
 1fa:	5f                   	pop    %rdi
 1fb:	62                   	(bad)  
 1fc:	61                   	(bad)  
 1fd:	73 65                	jae    264 <_init-0x400154>
 1ff:	00 04 18             	add    %al,(%rax,%rbx,1)
 202:	01 31                	add    %esi,(%rcx)
 204:	01 00                	add    %eax,(%rax)
 206:	00 02                	add    %al,(%rdx)
 208:	23 38                	and    (%rax),%edi
 20a:	08 5f 49             	or     %bl,0x49(%rdi)
 20d:	4f 5f                	rex64XYZ pop    %r15
 20f:	62                   	(bad)  
 210:	75 66                	jne    278 <_init-0x400140>
 212:	5f                   	pop    %rdi
 213:	65 6e                	outsb  %gs:(%rsi),(%dx)
 215:	64 00 04 19          	add    %al,%fs:(%rcx,%rbx,1)
 219:	01 31                	add    %esi,(%rcx)
 21b:	01 00                	add    %eax,(%rax)
 21d:	00 02                	add    %al,(%rdx)
 21f:	23 40 08             	and    0x8(%rax),%eax
 222:	5f                   	pop    %rdi
 223:	49                   	rex64Z
 224:	4f 5f                	rex64XYZ pop    %r15
 226:	73 61                	jae    289 <_init-0x40012f>
 228:	76 65                	jbe    28f <_init-0x400129>
 22a:	5f                   	pop    %rdi
 22b:	62                   	(bad)  
 22c:	61                   	(bad)  
 22d:	73 65                	jae    294 <_init-0x400124>
 22f:	00 04 1b             	add    %al,(%rbx,%rbx,1)
 232:	01 31                	add    %esi,(%rcx)
 234:	01 00                	add    %eax,(%rax)
 236:	00 02                	add    %al,(%rdx)
 238:	23 48 08             	and    0x8(%rax),%ecx
 23b:	5f                   	pop    %rdi
 23c:	49                   	rex64Z
 23d:	4f 5f                	rex64XYZ pop    %r15
 23f:	62                   	(bad)  
 240:	61                   	(bad)  
 241:	63 6b 75             	movslq 0x75(%rbx),%ebp
 244:	70 5f                	jo     2a5 <_init-0x400113>
 246:	62                   	(bad)  
 247:	61                   	(bad)  
 248:	73 65                	jae    2af <_init-0x400109>
 24a:	00 04 1c             	add    %al,(%rsp,%rbx,1)
 24d:	01 31                	add    %esi,(%rcx)
 24f:	01 00                	add    %eax,(%rax)
 251:	00 02                	add    %al,(%rdx)
 253:	23 50 08             	and    0x8(%rax),%edx
 256:	5f                   	pop    %rdi
 257:	49                   	rex64Z
 258:	4f 5f                	rex64XYZ pop    %r15
 25a:	73 61                	jae    2bd <_init-0x4000fb>
 25c:	76 65                	jbe    2c3 <_init-0x4000f5>
 25e:	5f                   	pop    %rdi
 25f:	65 6e                	outsb  %gs:(%rsi),(%dx)
 261:	64 00 04 1d 01 31 01 	add    %al,%fs:0x13101(,%rbx,1)
 268:	00 
 269:	00 02                	add    %al,(%rdx)
 26b:	23 58 08             	and    0x8(%rax),%ebx
 26e:	5f                   	pop    %rdi
 26f:	6d                   	insl   (%dx),%es:(%rdi)
 270:	61                   	(bad)  
 271:	72 6b                	jb     2de <_init-0x4000da>
 273:	65                   	gs
 274:	72 73                	jb     2e9 <_init-0x4000cf>
 276:	00 04 1f             	add    %al,(%rdi,%rbx,1)
 279:	01 22                	add    %esp,(%rdx)
 27b:	04 00                	add    $0x0,%al
 27d:	00 02                	add    %al,(%rdx)
 27f:	23 60 08             	and    0x8(%rax),%esp
 282:	5f                   	pop    %rdi
 283:	63 68 61             	movslq 0x61(%rax),%ebp
 286:	69 6e 00 04 21 01 28 	imul   $0x28012104,0x0(%rsi),%ebp
 28d:	04 00                	add    $0x0,%al
 28f:	00 02                	add    %al,(%rdx)
 291:	23 68 08             	and    0x8(%rax),%ebp
 294:	5f                   	pop    %rdi
 295:	66 69 6c 65 6e 6f 00 	imul   $0x6f,0x6e(%rbp,2),%bp
 29c:	04 23                	add    $0x23,%al
 29e:	01 f5                	add    %esi,%ebp
 2a0:	00 00                	add    %al,(%rax)
 2a2:	00 02                	add    %al,(%rdx)
 2a4:	23 70 08             	and    0x8(%rax),%esi
 2a7:	5f                   	pop    %rdi
 2a8:	66                   	data16
 2a9:	6c                   	insb   (%dx),%es:(%rdi)
 2aa:	61                   	(bad)  
 2ab:	67 73 32             	addr32 jae 2e0 <_init-0x4000d8>
 2ae:	00 04 27             	add    %al,(%rdi)
 2b1:	01 f5                	add    %esi,%ebp
 2b3:	00 00                	add    %al,(%rax)
 2b5:	00 02                	add    %al,(%rdx)
 2b7:	23 74 08 5f          	and    0x5f(%rax,%rcx,1),%esi
 2bb:	6f                   	outsl  %ds:(%rsi),(%dx)
 2bc:	6c                   	insb   (%dx),%es:(%rdi)
 2bd:	64                   	fs
 2be:	5f                   	pop    %rdi
 2bf:	6f                   	outsl  %ds:(%rsi),(%dx)
 2c0:	66                   	data16
 2c1:	66                   	data16
 2c2:	73 65                	jae    329 <_init-0x40008f>
 2c4:	74 00                	je     2c6 <_init-0x4000f2>
 2c6:	04 29                	add    $0x29,%al
 2c8:	01 08                	add    %ecx,(%rax)
 2ca:	01 00                	add    %eax,(%rax)
 2cc:	00 02                	add    %al,(%rdx)
 2ce:	23 78 08             	and    0x8(%rax),%edi
 2d1:	5f                   	pop    %rdi
 2d2:	63 75 72             	movslq 0x72(%rbp),%esi
 2d5:	5f                   	pop    %rdi
 2d6:	63 6f 6c             	movslq 0x6c(%rdi),%ebp
 2d9:	75 6d                	jne    348 <_init-0x400070>
 2db:	6e                   	outsb  %ds:(%rsi),(%dx)
 2dc:	00 04 2d 01 b3 00 00 	add    %al,0xb301(,%rbp,1)
 2e3:	00 03                	add    %al,(%rbx)
 2e5:	23 80 01 08 5f 76    	and    0x765f0801(%rax),%eax
 2eb:	74 61                	je     34e <_init-0x40006a>
 2ed:	62                   	(bad)  
 2ee:	6c                   	insb   (%dx),%es:(%rdi)
 2ef:	65                   	gs
 2f0:	5f                   	pop    %rdi
 2f1:	6f                   	outsl  %ds:(%rsi),(%dx)
 2f2:	66                   	data16
 2f3:	66                   	data16
 2f4:	73 65                	jae    35b <_init-0x40005d>
 2f6:	74 00                	je     2f8 <_init-0x4000c0>
 2f8:	04 2e                	add    $0x2e,%al
 2fa:	01 d9                	add    %ebx,%ecx
 2fc:	00 00                	add    %al,(%rax)
 2fe:	00 03                	add    %al,(%rbx)
 300:	23 82 01 08 5f 73    	and    0x735f0801(%rdx),%eax
 306:	68 6f 72 74 62       	pushq  $0x6274726f
 30b:	75 66                	jne    373 <_init-0x400045>
 30d:	00 04 2f             	add    %al,(%rdi,%rbp,1)
 310:	01 2e                	add    %ebp,(%rsi)
 312:	04 00                	add    $0x0,%al
 314:	00 03                	add    %al,(%rbx)
 316:	23 83 01 08 5f 6c    	and    0x6c5f0801(%rbx),%eax
 31c:	6f                   	outsl  %ds:(%rsi),(%dx)
 31d:	63 6b 00             	movslq 0x0(%rbx),%ebp
 320:	04 33                	add    $0x33,%al
 322:	01 3e                	add    %edi,(%rsi)
 324:	04 00                	add    $0x0,%al
 326:	00 03                	add    %al,(%rbx)
 328:	23 88 01 08 5f 6f    	and    0x6f5f0801(%rax),%ecx
 32e:	66                   	data16
 32f:	66                   	data16
 330:	73 65                	jae    397 <_init-0x400021>
 332:	74 00                	je     334 <_init-0x400084>
 334:	04 3c                	add    $0x3c,%al
 336:	01 17                	add    %edx,(%rdi)
 338:	01 00                	add    %eax,(%rax)
 33a:	00 03                	add    %al,(%rbx)
 33c:	23 90 01 08 5f 5f    	and    0x5f5f0801(%rax),%edx
 342:	70 61                	jo     3a5 <_init-0x400013>
 344:	64 31 00             	xor    %eax,%fs:(%rax)
 347:	04 45                	add    $0x45,%al
 349:	01 2f                	add    %ebp,(%rdi)
 34b:	01 00                	add    %eax,(%rax)
 34d:	00 03                	add    %al,(%rbx)
 34f:	23 98 01 08 5f 5f    	and    0x5f5f0801(%rax),%ebx
 355:	70 61                	jo     3b8 <_init-0x400000>
 357:	64 32 00             	xor    %fs:(%rax),%al
 35a:	04 46                	add    $0x46,%al
 35c:	01 2f                	add    %ebp,(%rdi)
 35e:	01 00                	add    %eax,(%rax)
 360:	00 03                	add    %al,(%rbx)
 362:	23 a0 01 08 5f 5f    	and    0x5f5f0801(%rax),%esp
 368:	70 61                	jo     3cb <_init-0x3fffed>
 36a:	64 33 00             	xor    %fs:(%rax),%eax
 36d:	04 47                	add    $0x47,%al
 36f:	01 2f                	add    %ebp,(%rdi)
 371:	01 00                	add    %eax,(%rax)
 373:	00 03                	add    %al,(%rbx)
 375:	23 a8 01 08 5f 5f    	and    0x5f5f0801(%rax),%ebp
 37b:	70 61                	jo     3de <_init-0x3fffda>
 37d:	64                   	fs
 37e:	34 00                	xor    $0x0,%al
 380:	04 48                	add    $0x48,%al
 382:	01 2f                	add    %ebp,(%rdi)
 384:	01 00                	add    %eax,(%rax)
 386:	00 03                	add    %al,(%rbx)
 388:	23 b0 01 08 5f 5f    	and    0x5f5f0801(%rax),%esi
 38e:	70 61                	jo     3f1 <_init-0x3fffc7>
 390:	64                   	fs
 391:	35 00 04 49 01       	xor    $0x1490400,%eax
 396:	8d 00                	lea    (%rax),%eax
 398:	00 00                	add    %al,(%rax)
 39a:	03 23                	add    (%rbx),%esp
 39c:	b8 01 08 5f 6d       	mov    $0x6d5f0801,%eax
 3a1:	6f                   	outsl  %ds:(%rsi),(%dx)
 3a2:	64 65 00 04 4b       	add    %al,%fs:%gs:(%rbx,%rcx,2)
 3a7:	01 f5                	add    %esi,%ebp
 3a9:	00 00                	add    %al,(%rax)
 3ab:	00 03                	add    %al,(%rbx)
 3ad:	23 c0                	and    %eax,%eax
 3af:	01 08                	add    %ecx,(%rax)
 3b1:	5f                   	pop    %rdi
 3b2:	75 6e                	jne    422 <_init-0x3fff96>
 3b4:	75 73                	jne    429 <_init-0x3fff8f>
 3b6:	65 64 32 00          	xor    %fs:%gs:(%rax),%al
 3ba:	04 4d                	add    $0x4d,%al
 3bc:	01 44 04 00          	add    %eax,0x0(%rsp,%rax,1)
 3c0:	00 03                	add    %al,(%rbx)
 3c2:	23 c4                	and    %esp,%eax
 3c4:	01 00                	add    %eax,(%rax)
 3c6:	06                   	(bad)  
 3c7:	08 cc                	or     %cl,%ah
 3c9:	03 00                	add    (%rax),%eax
 3cb:	00 09                	add    %cl,(%rcx)
 3cd:	37                   	(bad)  
 3ce:	01 00                	add    %eax,(%rax)
 3d0:	00 0a                	add    %cl,(%rdx)
 3d2:	5f                   	pop    %rdi
 3d3:	49                   	rex64Z
 3d4:	4f 5f                	rex64XYZ pop    %r15
 3d6:	6c                   	insb   (%dx),%es:(%rdi)
 3d7:	6f                   	outsl  %ds:(%rsi),(%dx)
 3d8:	63 6b 5f             	movslq 0x5f(%rbx),%ebp
 3db:	74 00                	je     3dd <_init-0x3fffdb>
 3dd:	04 b1                	add    $0xb1,%al
 3df:	0b 22                	or     (%rdx),%esp
 3e1:	04 00                	add    $0x0,%al
 3e3:	00 5f 49             	add    %bl,0x49(%rdi)
 3e6:	4f 5f                	rex64XYZ pop    %r15
 3e8:	6d                   	insl   (%dx),%es:(%rdi)
 3e9:	61                   	(bad)  
 3ea:	72 6b                	jb     457 <_init-0x3fff61>
 3ec:	65                   	gs
 3ed:	72 00                	jb     3ef <_init-0x3fffc9>
 3ef:	18 04 b7             	sbb    %al,(%rdi,%rsi,4)
 3f2:	0c 5f                	or     $0x5f,%al
 3f4:	6e                   	outsb  %ds:(%rsi),(%dx)
 3f5:	65                   	gs
 3f6:	78 74                	js     46c <_init-0x3fff4c>
 3f8:	00 04 b8             	add    %al,(%rax,%rdi,4)
 3fb:	22 04 00             	and    (%rax,%rax,1),%al
 3fe:	00 02                	add    %al,(%rdx)
 400:	23 00                	and    (%rax),%eax
 402:	0c 5f                	or     $0x5f,%al
 404:	73 62                	jae    468 <_init-0x3fff50>
 406:	75 66                	jne    46e <_init-0x3fff4a>
 408:	00 04 b9             	add    %al,(%rcx,%rdi,4)
 40b:	28 04 00             	sub    %al,(%rax,%rax,1)
 40e:	00 02                	add    %al,(%rdx)
 410:	23 08                	and    (%rax),%ecx
 412:	0c 5f                	or     $0x5f,%al
 414:	70 6f                	jo     485 <_init-0x3fff33>
 416:	73 00                	jae    418 <_init-0x3fffa0>
 418:	04 bd                	add    $0xbd,%al
 41a:	f5                   	cmc    
 41b:	00 00                	add    %al,(%rax)
 41d:	00 02                	add    %al,(%rdx)
 41f:	23 10                	and    (%rax),%edx
 421:	00 06                	add    %al,(%rsi)
 423:	08 df                	or     %bl,%bh
 425:	03 00                	add    (%rax),%eax
 427:	00 06                	add    %al,(%rsi)
 429:	08 3f                	or     %bh,(%rdi)
 42b:	01 00                	add    %eax,(%rax)
 42d:	00 0d 3e 04 00 00    	add    %cl,1086(%rip)        # 871 <_init-0x3ffb47>
 433:	37                   	(bad)  
 434:	01 00                	add    %eax,(%rax)
 436:	00 0e                	add    %cl,(%rsi)
 438:	28 01                	sub    %al,(%rcx)
 43a:	00 00                	add    %al,(%rax)
 43c:	00 00                	add    %al,(%rax)
 43e:	06                   	(bad)  
 43f:	08 d1                	or     %dl,%cl
 441:	03 00                	add    (%rax),%eax
 443:	00 0d 54 04 00 00    	add    %cl,1108(%rip)        # 89d <_init-0x3ffb1b>
 449:	37                   	(bad)  
 44a:	01 00                	add    %eax,(%rax)
 44c:	00 0e                	add    %cl,(%rsi)
 44e:	28 01                	sub    %al,(%rcx)
 450:	00 00                	add    %al,(%rax)
 452:	13 00                	adc    (%rax),%eax
 454:	0b b4 04 00 00 52 65 	or     0x65520000(%rsp,%rax,1),%esi
 45b:	71 75                	jno    4d2 <_init-0x3ffee6>
 45d:	65                   	gs
 45e:	73 74                	jae    4d4 <_init-0x3ffee4>
 460:	45 78 74             	rexXZ js     4d7 <_init-0x3ffee1>
 463:	65 6e                	outsb  %gs:(%rsi),(%dx)
 465:	73 69                	jae    4d0 <_init-0x3ffee8>
 467:	6f                   	outsl  %ds:(%rsi),(%dx)
 468:	6e                   	outsb  %ds:(%rsi),(%dx)
 469:	00 01                	add    %al,(%rcx)
 46b:	01 16                	add    %edx,(%rsi)
 46d:	0f 63 6c 69 65       	packsswb 0x65(%rcx,%rbp,2),%mm5
 472:	6e                   	outsb  %ds:(%rsi),(%dx)
 473:	74 5f                	je     4d4 <_init-0x3ffee4>
 475:	69 64 00 01 17 c9 00 	imul   $0xc917,0x1(%rax,%rax,1),%esp
 47c:	00 
 47d:	00 04 06             	add    %al,(%rsi,%rax,1)
 480:	1a 02                	sbb    (%rdx),%al
 482:	23 00                	and    (%rax),%eax
 484:	0f 69 6e 73          	punpckhwd 0x73(%rsi),%mm5
 488:	65                   	gs
 489:	72 74                	jb     4ff <_init-0x3ffeb9>
 48b:	5f                   	pop    %rdi
 48c:	68 6f 73 74 00       	pushq  $0x74736f
 491:	01 18                	add    %ebx,(%rax)
 493:	c9                   	leaveq 
 494:	00 00                	add    %al,(%rax)
 496:	00 04 01             	add    %al,(%rcx,%rax,1)
 499:	19 02                	sbb    %eax,(%rdx)
 49b:	23 00                	and    (%rax),%eax
 49d:	0f 72                	psrad  $0x72,(bad)
 49f:	65 64 69 72 65 63 74 	imul   $0x1007463,%fs:%gs:0x65(%rdx),%esi
 4a6:	00 01 
 4a8:	19 c9                	sbb    %ecx,%ecx
 4aa:	00 00                	add    %al,(%rax)
 4ac:	00 04 01             	add    %al,(%rcx,%rax,1)
 4af:	18 02                	sbb    %al,(%rdx)
 4b1:	23 00                	and    (%rax),%eax
 4b3:	00 10                	add    %dl,(%rax)
 4b5:	6a 05                	pushq  $0x5
 4b7:	00 00                	add    %al,(%rax)
 4b9:	01 62 69             	add    %esp,0x69(%rdx)
 4bc:	6e                   	outsb  %ds:(%rsi),(%dx)
 4bd:	32 68 65             	xor    0x65(%rax),%ch
 4c0:	78 00                	js     4c2 <_init-0x3ffef6>
 4c2:	01 1f                	add    %ebx,(%rdi)
 4c4:	01 8d 00 00 00 d8    	add    %ecx,0xffffffffd8000000(%rbp)
 4ca:	04 40                	add    $0x40,%al
 4cc:	00 00                	add    %al,(%rax)
 4ce:	00 00                	add    %al,(%rax)
 4d0:	00 87 05 40 00 00    	add    %al,0x4005(%rdi)
 4d6:	00 00                	add    %al,(%rax)
 4d8:	00 00                	add    %al,(%rax)
 4da:	00 00                	add    %al,(%rax)
 4dc:	00 11                	add    %dl,(%rcx)
 4de:	70 00                	jo     4e0 <_init-0x3ffed8>
 4e0:	01 1e                	add    %ebx,(%rsi)
 4e2:	c6 03 00             	movb   $0x0,(%rbx)
 4e5:	00 02                	add    %al,(%rdx)
 4e7:	91                   	xchg   %eax,%ecx
 4e8:	48 11 73 69          	adc    %rsi,0x69(%rbx)
 4ec:	7a 65                	jp     553 <_init-0x3ffe65>
 4ee:	00 01                	add    %al,(%rcx)
 4f0:	1e                   	(bad)  
 4f1:	8d 00                	lea    (%rax),%eax
 4f3:	00 00                	add    %al,(%rax)
 4f5:	02 91 40 11 68 65    	add    0x65681140(%rcx),%dl
 4fb:	78 5f                	js     55c <_init-0x3ffe5c>
 4fd:	73 74                	jae    573 <_init-0x3ffe45>
 4ff:	72 00                	jb     501 <_init-0x3ffeb7>
 501:	01 1e                	add    %ebx,(%rsi)
 503:	31 01                	xor    %eax,(%rcx)
 505:	00 00                	add    %al,(%rax)
 507:	03 91 b8 7f 11 68    	add    0x68117fb8(%rcx),%edx
 50d:	65                   	gs
 50e:	78 5f                	js     56f <_init-0x3ffe49>
 510:	73 74                	jae    586 <_init-0x3ffe32>
 512:	72 5f                	jb     573 <_init-0x3ffe45>
 514:	6d                   	insl   (%dx),%es:(%rdi)
 515:	61                   	(bad)  
 516:	78 00                	js     518 <_init-0x3ffea0>
 518:	01 1e                	add    %ebx,(%rsi)
 51a:	8d 00                	lea    (%rax),%eax
 51c:	00 00                	add    %al,(%rax)
 51e:	03 91 b0 7f 12 68    	add    0x68127fb0(%rcx),%edx
 524:	65                   	gs
 525:	78 5f                	js     586 <_init-0x3ffe32>
 527:	73 74                	jae    59d <_init-0x3ffe1b>
 529:	72 5f                	jb     58a <_init-0x3ffe2e>
 52b:	6c                   	insb   (%dx),%es:(%rdi)
 52c:	65 6e                	outsb  %gs:(%rsi),(%dx)
 52e:	00 01                	add    %al,(%rcx)
 530:	20 8d 00 00 00 02    	and    %cl,0x2000000(%rbp)
 536:	91                   	xchg   %eax,%ecx
 537:	58                   	pop    %rax
 538:	12 69 00             	adc    0x0(%rcx),%ch
 53b:	01 21                	add    %esp,(%rcx)
 53d:	8d 00                	lea    (%rax),%eax
 53f:	00 00                	add    %al,(%rax)
 541:	02 91 60 13 03 05    	add    0x5031360(%rcx),%dl
 547:	40 00 00             	add    %al,(%rax)
 54a:	00 00                	add    %al,(%rax)
 54c:	00 68 05             	add    %ch,0x5(%rax)
 54f:	40 00 00             	add    %al,(%rax)
 552:	00 00                	add    %al,(%rax)
 554:	00 12                	add    %dl,(%rdx)
 556:	63 75 72             	movslq 0x72(%rbp),%esi
 559:	5f                   	pop    %rdi
 55a:	63 68 61             	movslq 0x61(%rax),%ebp
 55d:	72 00                	jb     55f <_init-0x3ffe59>
 55f:	01 25 a2 00 00 00    	add    %esp,162(%rip)        # 607 <_init-0x3ffdb1>
 565:	02 91 6f 00 00 14    	add    0x1400006f(%rcx),%dl
 56b:	9e                   	(bad)  
 56c:	05 00 00 01 6d       	add    $0x6d010000,%eax
 571:	61                   	(bad)  
 572:	69 6e 00 01 2f f5 00 	imul   $0xf52f01,0x0(%rsi),%ebp
 579:	00 00                	add    %al,(%rax)
 57b:	87 05 40 00 00 00    	xchg   %eax,64(%rip)        # 5c1 <_init-0x3ffdf7>
 581:	00 00                	add    %al,(%rax)
 583:	f9                   	stc    
 584:	05 40 00 00 00       	add    $0x40,%eax
 589:	00 00                	add    %al,(%rax)
 58b:	4c 00 00             	rex64X add    %r8b,(%rax)
 58e:	00 12                	add    %dl,(%rdx)
 590:	65                   	gs
 591:	78 74                	js     607 <_init-0x3ffdb1>
 593:	00 01                	add    %al,(%rcx)
 595:	31 54 04 00          	xor    %edx,0x0(%rsp,%rax,1)
 599:	00 02                	add    %al,(%rdx)
 59b:	91                   	xchg   %eax,%ecx
 59c:	6f                   	outsl  %ds:(%rsi),(%dx)
 59d:	00 12                	add    %dl,(%rdx)
 59f:	48                   	rex64
 5a0:	65                   	gs
 5a1:	78 41                	js     5e4 <_init-0x3ffdd4>
 5a3:	6c                   	insb   (%dx),%es:(%rdi)
 5a4:	70 68                	jo     60e <_init-0x3ffdaa>
 5a6:	61                   	(bad)  
 5a7:	62                   	(bad)  
 5a8:	65                   	gs
 5a9:	74 00                	je     5ab <_init-0x3ffe0d>
 5ab:	01 1d c6 03 00 00    	add    %ebx,966(%rip)        # 977 <_init-0x3ffa41>
 5b1:	09 03                	or     %eax,(%rbx)
 5b3:	18 0a                	sbb    %cl,(%rdx)
 5b5:	60                   	(bad)  
 5b6:	00 00                	add    %al,(%rax)
 5b8:	00 00                	add    %al,(%rax)
 5ba:	00 15 73 74 64 65    	add    %dl,1701082227(%rip)        # 65647a33 <_end+0x65046ffb>
 5c0:	72 72                	jb     634 <_init-0x3ffd84>
 5c2:	00 03                	add    %al,(%rbx)
 5c4:	90                   	nop    
 5c5:	28 04 00             	sub    %al,(%rax,%rax,1)
 5c8:	00 01                	add    %al,(%rcx)
 5ca:	01 00                	add    %eax,(%rax)
Disassembly of section .debug_abbrev:

0000000000000000 <.debug_abbrev>:
   0:	01 11                	add    %edx,(%rcx)
   2:	01 10                	add    %edx,(%rax)
   4:	06                   	(bad)  
   5:	12 01                	adc    (%rcx),%al
   7:	11 01                	adc    %eax,(%rcx)
   9:	25 08 13 0b 03       	and    $0x30b1308,%eax
   e:	08 1b                	or     %bl,(%rbx)
  10:	08 00                	or     %al,(%rax)
  12:	00 02                	add    %al,(%rdx)
  14:	16                   	(bad)  
  15:	00 03                	add    %al,(%rbx)
  17:	08 3a                	or     %bh,(%rdx)
  19:	0b 3b                	or     (%rbx),%edi
  1b:	0b 49 13             	or     0x13(%rcx),%ecx
  1e:	00 00                	add    %al,(%rax)
  20:	03 24 00             	add    (%rax,%rax,1),%esp
  23:	03 0e                	add    (%rsi),%ecx
  25:	0b 0b                	or     (%rbx),%ecx
  27:	3e 0b 00             	or     %ds:(%rax),%eax
  2a:	00 04 24             	add    %al,(%rsp)
  2d:	00 03                	add    %al,(%rbx)
  2f:	08 0b                	or     %cl,(%rbx)
  31:	0b 3e                	or     (%rsi),%edi
  33:	0b 00                	or     (%rax),%eax
  35:	00 05 0f 00 0b 0b    	add    %al,185270287(%rip)        # b0b004a <_end+0xaaaf612>
  3b:	00 00                	add    %al,(%rax)
  3d:	06                   	(bad)  
  3e:	0f 00 0b             	str    (%rbx)
  41:	0b 49 13             	or     0x13(%rcx),%ecx
  44:	00 00                	add    %al,(%rax)
  46:	07                   	(bad)  
  47:	13 01                	adc    (%rcx),%eax
  49:	01 13                	add    %edx,(%rbx)
  4b:	03 0e                	add    (%rsi),%ecx
  4d:	0b 0b                	or     (%rbx),%ecx
  4f:	3a 0b                	cmp    (%rbx),%cl
  51:	3b 0b                	cmp    (%rbx),%ecx
  53:	00 00                	add    %al,(%rax)
  55:	08 0d 00 03 08 3a    	or     %cl,973603584(%rip)        # 3a08035b <_end+0x39a7f923>
  5b:	0b 3b                	or     (%rbx),%edi
  5d:	05 49 13 38 0a       	add    $0xa381349,%eax
  62:	00 00                	add    %al,(%rax)
  64:	09 26                	or     %esp,(%rsi)
  66:	00 49 13             	add    %cl,0x13(%rcx)
  69:	00 00                	add    %al,(%rax)
  6b:	0a 16                	or     (%rsi),%dl
  6d:	00 03                	add    %al,(%rbx)
  6f:	08 3a                	or     %bh,(%rdx)
  71:	0b 3b                	or     (%rbx),%edi
  73:	0b 00                	or     (%rax),%eax
  75:	00 0b                	add    %cl,(%rbx)
  77:	13 01                	adc    (%rcx),%eax
  79:	01 13                	add    %edx,(%rbx)
  7b:	03 08                	add    (%rax),%ecx
  7d:	0b 0b                	or     (%rbx),%ecx
  7f:	3a 0b                	cmp    (%rbx),%cl
  81:	3b 0b                	cmp    (%rbx),%ecx
  83:	00 00                	add    %al,(%rax)
  85:	0c 0d                	or     $0xd,%al
  87:	00 03                	add    %al,(%rbx)
  89:	08 3a                	or     %bh,(%rdx)
  8b:	0b 3b                	or     (%rbx),%edi
  8d:	0b 49 13             	or     0x13(%rcx),%ecx
  90:	38 0a                	cmp    %cl,(%rdx)
  92:	00 00                	add    %al,(%rax)
  94:	0d 01 01 01 13       	or     $0x13010101,%eax
  99:	49 13 00             	adc    (%r8),%rax
  9c:	00 0e                	add    %cl,(%rsi)
  9e:	21 00                	and    %eax,(%rax)
  a0:	49 13 2f             	adc    (%r15),%rbp
  a3:	0b 00                	or     (%rax),%eax
  a5:	00 0f                	add    %cl,(%rdi)
  a7:	0d 00 03 08 3a       	or     $0x3a080300,%eax
  ac:	0b 3b                	or     (%rbx),%edi
  ae:	0b 49 13             	or     0x13(%rcx),%ecx
  b1:	0b 0b                	or     (%rbx),%ecx
  b3:	0d 0b 0c 0b 38       	or     $0x380b0c0b,%eax
  b8:	0a 00                	or     (%rax),%al
  ba:	00 10                	add    %dl,(%rax)
  bc:	2e 01 01             	add    %eax,%cs:(%rcx)
  bf:	13 3f                	adc    (%rdi),%edi
  c1:	0c 03                	or     $0x3,%al
  c3:	08 3a                	or     %bh,(%rdx)
  c5:	0b 3b                	or     (%rbx),%edi
  c7:	0b 27                	or     (%rdi),%esp
  c9:	0c 49                	or     $0x49,%al
  cb:	13 11                	adc    (%rcx),%edx
  cd:	01 12                	add    %edx,(%rdx)
  cf:	01 40 06             	add    %eax,0x6(%rax)
  d2:	00 00                	add    %al,(%rax)
  d4:	11 05 00 03 08 3a    	adc    %eax,973603584(%rip)        # 3a0803da <_end+0x39a7f9a2>
  da:	0b 3b                	or     (%rbx),%edi
  dc:	0b 49 13             	or     0x13(%rcx),%ecx
  df:	02 0a                	add    (%rdx),%cl
  e1:	00 00                	add    %al,(%rax)
  e3:	12 34 00             	adc    (%rax,%rax,1),%dh
  e6:	03 08                	add    (%rax),%ecx
  e8:	3a 0b                	cmp    (%rbx),%cl
  ea:	3b 0b                	cmp    (%rbx),%ecx
  ec:	49 13 02             	adc    (%r10),%rax
  ef:	0a 00                	or     (%rax),%al
  f1:	00 13                	add    %dl,(%rbx)
  f3:	0b 01                	or     (%rcx),%eax
  f5:	11 01                	adc    %eax,(%rcx)
  f7:	12 01                	adc    (%rcx),%al
  f9:	00 00                	add    %al,(%rax)
  fb:	14 2e                	adc    $0x2e,%al
  fd:	01 01                	add    %eax,(%rcx)
  ff:	13 3f                	adc    (%rdi),%edi
 101:	0c 03                	or     $0x3,%al
 103:	08 3a                	or     %bh,(%rdx)
 105:	0b 3b                	or     (%rbx),%edi
 107:	0b 49 13             	or     0x13(%rcx),%ecx
 10a:	11 01                	adc    %eax,(%rcx)
 10c:	12 01                	adc    (%rcx),%al
 10e:	40 06                	rex (bad)  
 110:	00 00                	add    %al,(%rax)
 112:	15 34 00 03 08       	adc    $0x8030034,%eax
 117:	3a 0b                	cmp    (%rbx),%cl
 119:	3b 0b                	cmp    (%rbx),%ecx
 11b:	49 13 3f             	adc    (%r15),%rdi
 11e:	0c 3c                	or     $0x3c,%al
 120:	0c 00                	or     $0x0,%al
	...
Disassembly of section .debug_line:

0000000000000000 <.debug_line>:
   0:	d5                   	(bad)  
   1:	00 00                	add    %al,(%rax)
   3:	00 02                	add    %al,(%rdx)
   5:	00 a3 00 00 00 01    	add    %ah,0x1000000(%rbx)
   b:	01 fb                	add    %edi,%ebx
   d:	0e                   	(bad)  
   e:	0d 00 01 01 01       	or     $0x1010100,%eax
  13:	01 00                	add    %eax,(%rax)
  15:	00 00                	add    %al,(%rax)
  17:	01 00                	add    %eax,(%rax)
  19:	00 01                	add    %al,(%rcx)
  1b:	2f                   	(bad)  
  1c:	75 73                	jne    91 <_init-0x400327>
  1e:	72 2f                	jb     4f <_init-0x400369>
  20:	6c                   	insb   (%dx),%es:(%rdi)
  21:	69 62 2f 67 63 63 2f 	imul   $0x2f636367,0x2f(%rdx),%esp
  28:	78 38                	js     62 <_init-0x400356>
  2a:	36                   	ss
  2b:	5f                   	pop    %rdi
  2c:	36                   	ss
  2d:	34 2d                	xor    $0x2d,%al
  2f:	72 65                	jb     96 <_init-0x400322>
  31:	64                   	fs
  32:	68 61 74 2d 6c       	pushq  $0x6c2d7461
  37:	69 6e 75 78 2f 34 2e 	imul   $0x2e342f78,0x75(%rsi),%ebp
  3e:	31 2e                	xor    %ebp,(%rsi)
  40:	32 2f                	xor    (%rdi),%ch
  42:	69 6e 63 6c 75 64 65 	imul   $0x6564756c,0x63(%rsi),%ebp
  49:	00 2f                	add    %ch,(%rdi)
  4b:	75 73                	jne    c0 <_init-0x4002f8>
  4d:	72 2f                	jb     7e <_init-0x40033a>
  4f:	69 6e 63 6c 75 64 65 	imul   $0x6564756c,0x63(%rsi),%ebp
  56:	00 2f                	add    %ch,(%rdi)
  58:	75 73                	jne    cd <_init-0x4002eb>
  5a:	72 2f                	jb     8b <_init-0x40032d>
  5c:	69 6e 63 6c 75 64 65 	imul   $0x6564756c,0x63(%rsi),%ebp
  63:	2f                   	(bad)  
  64:	62                   	(bad)  
  65:	69 74 73 00 00 74 65 	imul   $0x73657400,0x0(%rbx,%rsi,2),%esi
  6c:	73 
  6d:	74 5f                	je     ce <_init-0x4002ea>
  6f:	6d                   	insl   (%dx),%es:(%rdi)
  70:	65                   	gs
  71:	6d                   	insl   (%dx),%es:(%rdi)
  72:	5f                   	pop    %rdi
  73:	6c                   	insb   (%dx),%es:(%rdi)
  74:	61                   	(bad)  
  75:	79 6f                	jns    e6 <_init-0x4002d2>
  77:	75 74                	jne    ed <_init-0x4002cb>
  79:	2e 63 00             	movslq %cs:(%rax),%eax
  7c:	00 00                	add    %al,(%rax)
  7e:	00 73 74             	add    %dh,0x74(%rbx)
  81:	64                   	fs
  82:	64                   	fs
  83:	65                   	gs
  84:	66                   	data16
  85:	2e                   	cs
  86:	68 00 01 00 00       	pushq  $0x100
  8b:	73 74                	jae    101 <_init-0x4002b7>
  8d:	64 69 6f 2e 68 00 02 	imul   $0x20068,%fs:0x2e(%rdi),%ebp
  94:	00 
  95:	00 6c 69 62          	add    %ch,0x62(%rcx,%rbp,2)
  99:	69 6f 2e 68 00 02 00 	imul   $0x20068,0x2e(%rdi),%ebp
  a0:	00 74 79 70          	add    %dh,0x70(%rcx,%rdi,2)
  a4:	65                   	gs
  a5:	73 2e                	jae    d5 <_init-0x4002e3>
  a7:	68 00 03 00 00       	pushq  $0x300
  ac:	00 00                	add    %al,(%rax)
  ae:	09 02                	or     %eax,(%rdx)
  b0:	d8 04 40             	fadds  (%rax,%rax,2)
  b3:	00 00                	add    %al,(%rax)
  b5:	00 00                	add    %al,(%rax)
  b7:	00 03                	add    %al,(%rbx)
  b9:	1e                   	(bad)  
  ba:	01 08                	add    %ecx,(%rax)
  bc:	3d 85 59 9f d7       	cmp    $0xd79f5985,%eax
  c1:	02 28                	add    (%rax),%ch
  c3:	13 02                	adc    (%rdx),%eax
  c5:	2a 13                	sub    (%rbx),%dl
  c7:	54                   	push   %rsp
  c8:	08 89 4b 31 85 c9    	or     %cl,0xffffffffc985314b(%rcx)
  ce:	9f                   	(bad)  
  cf:	a3 02 42 16 59 02 02 	mov    %eax,0x100020259164202
  d6:	00 01 
  d8:	01                   	.byte 0x1
Disassembly of section .debug_frame:

0000000000000000 <.debug_frame>:
   0:	14 00                	adc    $0x0,%al
   2:	00 00                	add    %al,(%rax)
   4:	ff                   	(bad)  
   5:	ff                   	(bad)  
   6:	ff                   	(bad)  
   7:	ff 01                	incl   (%rcx)
   9:	00 01                	add    %al,(%rcx)
   b:	78 10                	js     1d <_init-0x40039b>
   d:	0c 07                	or     $0x7,%al
   f:	08 90 01 00 00 00    	or     %dl,0x1(%rax)
  15:	00 00                	add    %al,(%rax)
  17:	00 1c 00             	add    %bl,(%rax,%rax,1)
  1a:	00 00                	add    %al,(%rax)
  1c:	00 00                	add    %al,(%rax)
  1e:	00 00                	add    %al,(%rax)
  20:	d8 04 40             	fadds  (%rax,%rax,2)
  23:	00 00                	add    %al,(%rax)
  25:	00 00                	add    %al,(%rax)
  27:	00 af 00 00 00 00    	add    %ch,0x0(%rdi)
  2d:	00 00                	add    %al,(%rax)
  2f:	00 41 0e             	add    %al,0xe(%rcx)
  32:	10 86 02 43 0d 06    	adc    %al,0x60d4302(%rsi)
  38:	1c 00                	sbb    $0x0,%al
  3a:	00 00                	add    %al,(%rax)
  3c:	00 00                	add    %al,(%rax)
  3e:	00 00                	add    %al,(%rax)
  40:	87 05 40 00 00 00    	xchg   %eax,64(%rip)        # 86 <_init-0x400332>
  46:	00 00                	add    %al,(%rax)
  48:	72 00                	jb     4a <_init-0x40036e>
  4a:	00 00                	add    %al,(%rax)
  4c:	00 00                	add    %al,(%rax)
  4e:	00 00                	add    %al,(%rax)
  50:	41 0e                	rexZ (bad)  
  52:	10 86 02 43 0d 06    	adc    %al,0x60d4302(%rsi)
Disassembly of section .debug_str:

0000000000000000 <.debug_str>:
   0:	6c                   	insb   (%dx),%es:(%rdi)
   1:	6f                   	outsl  %ds:(%rsi),(%dx)
   2:	6e                   	outsb  %ds:(%rsi),(%dx)
   3:	67 20 75 6e          	addr32 and %dh,0x6e(%ebp)
   7:	73 69                	jae    72 <_init-0x400346>
   9:	67 6e                	addr32 outsb %ds:(%esi),(%dx)
   b:	65 64 20 69 6e       	and    %ch,%fs:%gs:0x6e(%rcx)
  10:	74 00                	je     12 <_init-0x4003a6>
  12:	5f                   	pop    %rdi
  13:	49                   	rex64Z
  14:	4f 5f                	rex64XYZ pop    %r15
  16:	46                   	rexXY
  17:	49                   	rex64Z
  18:	4c                   	rex64X
  19:	45                   	rexXZ
	...
Disassembly of section .debug_loc:

0000000000000000 <.debug_loc>:
	...
   8:	01 00                	add    %eax,(%rax)
   a:	00 00                	add    %al,(%rax)
   c:	00 00                	add    %al,(%rax)
   e:	00 00                	add    %al,(%rax)
  10:	02 00                	add    (%rax),%al
  12:	77 08                	ja     1c <_init-0x40039c>
  14:	01 00                	add    %eax,(%rax)
  16:	00 00                	add    %al,(%rax)
  18:	00 00                	add    %al,(%rax)
  1a:	00 00                	add    %al,(%rax)
  1c:	04 00                	add    $0x0,%al
  1e:	00 00                	add    %al,(%rax)
  20:	00 00                	add    %al,(%rax)
  22:	00 00                	add    %al,(%rax)
  24:	02 00                	add    (%rax),%al
  26:	77 10                	ja     38 <_init-0x400380>
  28:	04 00                	add    $0x0,%al
  2a:	00 00                	add    %al,(%rax)
  2c:	00 00                	add    %al,(%rax)
  2e:	00 00                	add    %al,(%rax)
  30:	af                   	scas   %es:(%rdi),%eax
  31:	00 00                	add    %al,(%rax)
  33:	00 00                	add    %al,(%rax)
  35:	00 00                	add    %al,(%rax)
  37:	00 02                	add    %al,(%rdx)
  39:	00 76 10             	add    %dh,0x10(%rsi)
	...
  4c:	af                   	scas   %es:(%rdi),%eax
  4d:	00 00                	add    %al,(%rax)
  4f:	00 00                	add    %al,(%rax)
  51:	00 00                	add    %al,(%rax)
  53:	00 b0 00 00 00 00    	add    %dh,0x0(%rax)
  59:	00 00                	add    %al,(%rax)
  5b:	00 02                	add    %al,(%rdx)
  5d:	00 77 08             	add    %dh,0x8(%rdi)
  60:	b0 00                	mov    $0x0,%al
  62:	00 00                	add    %al,(%rax)
  64:	00 00                	add    %al,(%rax)
  66:	00 00                	add    %al,(%rax)
  68:	b3 00                	mov    $0x0,%bl
  6a:	00 00                	add    %al,(%rax)
  6c:	00 00                	add    %al,(%rax)
  6e:	00 00                	add    %al,(%rax)
  70:	02 00                	add    (%rax),%al
  72:	77 10                	ja     84 <_init-0x400334>
  74:	b3 00                	mov    $0x0,%bl
  76:	00 00                	add    %al,(%rax)
  78:	00 00                	add    %al,(%rax)
  7a:	00 00                	add    %al,(%rax)
  7c:	21 01                	and    %eax,(%rcx)
  7e:	00 00                	add    %al,(%rax)
  80:	00 00                	add    %al,(%rax)
  82:	00 00                	add    %al,(%rax)
  84:	02 00                	add    (%rax),%al
  86:	76 10                	jbe    98 <_init-0x400320>
	...
