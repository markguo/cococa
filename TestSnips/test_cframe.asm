
test_cframe:     file format elf64-x86-64

Disassembly of section .init:

0000000000400408 <_init>:
  400408:	48 83 ec 08          	sub    $0x8,%rsp
  40040c:	e8 6b 00 00 00       	callq  40047c <call_gmon_start>
  400411:	e8 ea 00 00 00       	callq  400500 <frame_dummy>
  400416:	e8 45 02 00 00       	callq  400660 <__do_global_ctors_aux>
  40041b:	48 83 c4 08          	add    $0x8,%rsp
  40041f:	c3                   	retq   
Disassembly of section .plt:

0000000000400420 <__libc_start_main@plt-0x10>:
  400420:	ff 35 a2 05 20 00    	pushq  2098594(%rip)        # 6009c8 <_GLOBAL_OFFSET_TABLE_+0x8>
  400426:	ff 25 a4 05 20 00    	jmpq   *2098596(%rip)        # 6009d0 <_GLOBAL_OFFSET_TABLE_+0x10>
  40042c:	0f 1f 40 00          	nopl   0x0(%rax)

0000000000400430 <__libc_start_main@plt>:
  400430:	ff 25 a2 05 20 00    	jmpq   *2098594(%rip)        # 6009d8 <_GLOBAL_OFFSET_TABLE_+0x18>
  400436:	68 00 00 00 00       	pushq  $0x0
  40043b:	e9 e0 ff ff ff       	jmpq   400420 <_init+0x18>

0000000000400440 <__gxx_personality_v0@plt>:
  400440:	ff 25 9a 05 20 00    	jmpq   *2098586(%rip)        # 6009e0 <_GLOBAL_OFFSET_TABLE_+0x20>
  400446:	68 01 00 00 00       	pushq  $0x1
  40044b:	e9 d0 ff ff ff       	jmpq   400420 <_init+0x18>
Disassembly of section .text:

0000000000400450 <_start>:
  400450:	31 ed                	xor    %ebp,%ebp
  400452:	49 89 d1             	mov    %rdx,%r9
  400455:	5e                   	pop    %rsi
  400456:	48 89 e2             	mov    %rsp,%rdx
  400459:	48 83 e4 f0          	and    $0xfffffffffffffff0,%rsp
  40045d:	50                   	push   %rax
  40045e:	54                   	push   %rsp
  40045f:	49 c7 c0 c0 05 40 00 	mov    $0x4005c0,%r8
  400466:	48 c7 c1 d0 05 40 00 	mov    $0x4005d0,%rcx
  40046d:	48 c7 c7 74 05 40 00 	mov    $0x400574,%rdi
  400474:	e8 b7 ff ff ff       	callq  400430 <__libc_start_main@plt>
  400479:	f4                   	hlt    
  40047a:	90                   	nop    
  40047b:	90                   	nop    

000000000040047c <call_gmon_start>:
  40047c:	48 83 ec 08          	sub    $0x8,%rsp
  400480:	48 8b 05 31 05 20 00 	mov    2098481(%rip),%rax        # 6009b8 <_DYNAMIC+0x1c0>
  400487:	48 85 c0             	test   %rax,%rax
  40048a:	74 02                	je     40048e <call_gmon_start+0x12>
  40048c:	ff d0                	callq  *%rax
  40048e:	48 83 c4 08          	add    $0x8,%rsp
  400492:	c3                   	retq   
  400493:	90                   	nop    
  400494:	90                   	nop    
  400495:	90                   	nop    
  400496:	90                   	nop    
  400497:	90                   	nop    
  400498:	90                   	nop    
  400499:	90                   	nop    
  40049a:	90                   	nop    
  40049b:	90                   	nop    
  40049c:	90                   	nop    
  40049d:	90                   	nop    
  40049e:	90                   	nop    
  40049f:	90                   	nop    

00000000004004a0 <__do_global_dtors_aux>:
  4004a0:	55                   	push   %rbp
  4004a1:	48 89 e5             	mov    %rsp,%rbp
  4004a4:	53                   	push   %rbx
  4004a5:	48 83 ec 08          	sub    $0x8,%rsp
  4004a9:	80 3d 48 05 20 00 00 	cmpb   $0x0,2098504(%rip)        # 6009f8 <completed.6145>
  4004b0:	75 44                	jne    4004f6 <__do_global_dtors_aux+0x56>
  4004b2:	b8 e8 07 60 00       	mov    $0x6007e8,%eax
  4004b7:	48 2d e0 07 60 00    	sub    $0x6007e0,%rax
  4004bd:	48 c1 f8 03          	sar    $0x3,%rax
  4004c1:	48 8d 58 ff          	lea    0xffffffffffffffff(%rax),%rbx
  4004c5:	48 8b 05 24 05 20 00 	mov    2098468(%rip),%rax        # 6009f0 <dtor_idx.6147>
  4004cc:	48 39 c3             	cmp    %rax,%rbx
  4004cf:	76 1e                	jbe    4004ef <__do_global_dtors_aux+0x4f>
  4004d1:	48 83 c0 01          	add    $0x1,%rax
  4004d5:	48 89 05 14 05 20 00 	mov    %rax,2098452(%rip)        # 6009f0 <dtor_idx.6147>
  4004dc:	ff 14 c5 e0 07 60 00 	callq  *0x6007e0(,%rax,8)
  4004e3:	48 8b 05 06 05 20 00 	mov    2098438(%rip),%rax        # 6009f0 <dtor_idx.6147>
  4004ea:	48 39 c3             	cmp    %rax,%rbx
  4004ed:	77 e2                	ja     4004d1 <__do_global_dtors_aux+0x31>
  4004ef:	c6 05 02 05 20 00 01 	movb   $0x1,2098434(%rip)        # 6009f8 <completed.6145>
  4004f6:	48 83 c4 08          	add    $0x8,%rsp
  4004fa:	5b                   	pop    %rbx
  4004fb:	c9                   	leaveq 
  4004fc:	c3                   	retq   
  4004fd:	0f 1f 00             	nopl   (%rax)

0000000000400500 <frame_dummy>:
  400500:	55                   	push   %rbp
  400501:	48 83 3d e7 02 20 00 	cmpq   $0x0,2097895(%rip)        # 6007f0 <__JCR_END__>
  400508:	00 
  400509:	48 89 e5             	mov    %rsp,%rbp
  40050c:	74 16                	je     400524 <frame_dummy+0x24>
  40050e:	b8 00 00 00 00       	mov    $0x0,%eax
  400513:	48 85 c0             	test   %rax,%rax
  400516:	74 0c                	je     400524 <frame_dummy+0x24>
  400518:	bf f0 07 60 00       	mov    $0x6007f0,%edi
  40051d:	49 89 c3             	mov    %rax,%r11
  400520:	c9                   	leaveq 
  400521:	41 ff e3             	jmpq   *%r11
  400524:	c9                   	leaveq 
  400525:	c3                   	retq   
  400526:	90                   	nop    
  400527:	90                   	nop    

0000000000400528 <_Z8functioniii>:
  400528:	55                   	push   %rbp
  400529:	48 89 e5             	mov    %rsp,%rbp
  40052c:	89 7d dc             	mov    %edi,0xffffffffffffffdc(%rbp)
  40052f:	89 75 d8             	mov    %esi,0xffffffffffffffd8(%rbp)
  400532:	89 55 d4             	mov    %edx,0xffffffffffffffd4(%rbp)
  400535:	c7 45 fc 00 00 00 00 	movl   $0x0,0xfffffffffffffffc(%rbp)
  40053c:	8b 45 d8             	mov    0xffffffffffffffd8(%rbp),%eax
  40053f:	03 45 dc             	add    0xffffffffffffffdc(%rbp),%eax
  400542:	03 45 d4             	add    0xffffffffffffffd4(%rbp),%eax
  400545:	89 45 f8             	mov    %eax,0xfffffffffffffff8(%rbp)
  400548:	c7 45 fc 00 00 00 00 	movl   $0x0,0xfffffffffffffffc(%rbp)
  40054f:	eb 0e                	jmp    40055f <_Z8functioniii+0x37>
  400551:	8b 45 fc             	mov    0xfffffffffffffffc(%rbp),%eax
  400554:	48 98                	cltq   
  400556:	c6 44 05 e0 05       	movb   $0x5,0xffffffffffffffe0(%rbp,%rax,1)
  40055b:	83 45 fc 01          	addl   $0x1,0xfffffffffffffffc(%rbp)
  40055f:	83 7d fc 0d          	cmpl   $0xd,0xfffffffffffffffc(%rbp)
  400563:	7e ec                	jle    400551 <_Z8functioniii+0x29>
  400565:	8b 45 f8             	mov    0xfffffffffffffff8(%rbp),%eax
  400568:	c9                   	leaveq 
  400569:	c3                   	retq   

000000000040056a <_Z3fooPi>:
  40056a:	55                   	push   %rbp
  40056b:	48 89 e5             	mov    %rsp,%rbp
  40056e:	48 89 7d f8          	mov    %rdi,0xfffffffffffffff8(%rbp)
  400572:	c9                   	leaveq 
  400573:	c3                   	retq   

0000000000400574 <main>:
  400574:	55                   	push   %rbp
  400575:	48 89 e5             	mov    %rsp,%rbp
  400578:	48 83 ec 20          	sub    $0x20,%rsp
  40057c:	c7 45 e4 00 00 00 00 	movl   $0x0,0xffffffffffffffe4(%rbp)
  400583:	48 8d 45 e4          	lea    0xffffffffffffffe4(%rbp),%rax
  400587:	48 89 45 e8          	mov    %rax,0xffffffffffffffe8(%rbp)
  40058b:	48 8b 45 e8          	mov    0xffffffffffffffe8(%rbp),%rax
  40058f:	48 89 45 f0          	mov    %rax,0xfffffffffffffff0(%rbp)
  400593:	48 8b 7d e8          	mov    0xffffffffffffffe8(%rbp),%rdi
  400597:	e8 ce ff ff ff       	callq  40056a <_Z3fooPi>
  40059c:	48 8d 45 e4          	lea    0xffffffffffffffe4(%rbp),%rax
  4005a0:	48 89 45 f8          	mov    %rax,0xfffffffffffffff8(%rbp)
  4005a4:	48 8b 7d f8          	mov    0xfffffffffffffff8(%rbp),%rdi
  4005a8:	e8 bd ff ff ff       	callq  40056a <_Z3fooPi>
  4005ad:	b8 00 00 00 00       	mov    $0x0,%eax
  4005b2:	c9                   	leaveq 
  4005b3:	c3                   	retq   
  4005b4:	90                   	nop    
  4005b5:	90                   	nop    
  4005b6:	90                   	nop    
  4005b7:	90                   	nop    
  4005b8:	90                   	nop    
  4005b9:	90                   	nop    
  4005ba:	90                   	nop    
  4005bb:	90                   	nop    
  4005bc:	90                   	nop    
  4005bd:	90                   	nop    
  4005be:	90                   	nop    
  4005bf:	90                   	nop    

00000000004005c0 <__libc_csu_fini>:
  4005c0:	f3 c3                	repz retq 
  4005c2:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)
  4005c9:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)

00000000004005d0 <__libc_csu_init>:
  4005d0:	4c 89 64 24 e0       	mov    %r12,0xffffffffffffffe0(%rsp)
  4005d5:	4c 89 6c 24 e8       	mov    %r13,0xffffffffffffffe8(%rsp)
  4005da:	4c 8d 25 eb 01 20 00 	lea    2097643(%rip),%r12        # 6007cc <__fini_array_end>
  4005e1:	4c 89 74 24 f0       	mov    %r14,0xfffffffffffffff0(%rsp)
  4005e6:	4c 89 7c 24 f8       	mov    %r15,0xfffffffffffffff8(%rsp)
  4005eb:	49 89 f6             	mov    %rsi,%r14
  4005ee:	48 89 5c 24 d0       	mov    %rbx,0xffffffffffffffd0(%rsp)
  4005f3:	48 89 6c 24 d8       	mov    %rbp,0xffffffffffffffd8(%rsp)
  4005f8:	48 83 ec 38          	sub    $0x38,%rsp
  4005fc:	41 89 ff             	mov    %edi,%r15d
  4005ff:	49 89 d5             	mov    %rdx,%r13
  400602:	e8 01 fe ff ff       	callq  400408 <_init>
  400607:	48 8d 05 be 01 20 00 	lea    2097598(%rip),%rax        # 6007cc <__fini_array_end>
  40060e:	49 29 c4             	sub    %rax,%r12
  400611:	49 c1 fc 03          	sar    $0x3,%r12
  400615:	4d 85 e4             	test   %r12,%r12
  400618:	74 1e                	je     400638 <__libc_csu_init+0x68>
  40061a:	31 ed                	xor    %ebp,%ebp
  40061c:	48 89 c3             	mov    %rax,%rbx
  40061f:	90                   	nop    
  400620:	48 83 c5 01          	add    $0x1,%rbp
  400624:	4c 89 ea             	mov    %r13,%rdx
  400627:	4c 89 f6             	mov    %r14,%rsi
  40062a:	44 89 ff             	mov    %r15d,%edi
  40062d:	ff 13                	callq  *(%rbx)
  40062f:	48 83 c3 08          	add    $0x8,%rbx
  400633:	49 39 ec             	cmp    %rbp,%r12
  400636:	75 e8                	jne    400620 <__libc_csu_init+0x50>
  400638:	48 8b 5c 24 08       	mov    0x8(%rsp),%rbx
  40063d:	48 8b 6c 24 10       	mov    0x10(%rsp),%rbp
  400642:	4c 8b 64 24 18       	mov    0x18(%rsp),%r12
  400647:	4c 8b 6c 24 20       	mov    0x20(%rsp),%r13
  40064c:	4c 8b 74 24 28       	mov    0x28(%rsp),%r14
  400651:	4c 8b 7c 24 30       	mov    0x30(%rsp),%r15
  400656:	48 83 c4 38          	add    $0x38,%rsp
  40065a:	c3                   	retq   
  40065b:	90                   	nop    
  40065c:	90                   	nop    
  40065d:	90                   	nop    
  40065e:	90                   	nop    
  40065f:	90                   	nop    

0000000000400660 <__do_global_ctors_aux>:
  400660:	55                   	push   %rbp
  400661:	48 89 e5             	mov    %rsp,%rbp
  400664:	53                   	push   %rbx
  400665:	bb d0 07 60 00       	mov    $0x6007d0,%ebx
  40066a:	48 83 ec 08          	sub    $0x8,%rsp
  40066e:	48 8b 05 5b 01 20 00 	mov    2097499(%rip),%rax        # 6007d0 <__CTOR_LIST__>
  400675:	48 83 f8 ff          	cmp    $0xffffffffffffffff,%rax
  400679:	74 14                	je     40068f <__do_global_ctors_aux+0x2f>
  40067b:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)
  400680:	48 83 eb 08          	sub    $0x8,%rbx
  400684:	ff d0                	callq  *%rax
  400686:	48 8b 03             	mov    (%rbx),%rax
  400689:	48 83 f8 ff          	cmp    $0xffffffffffffffff,%rax
  40068d:	75 f1                	jne    400680 <__do_global_ctors_aux+0x20>
  40068f:	48 83 c4 08          	add    $0x8,%rsp
  400693:	5b                   	pop    %rbx
  400694:	c9                   	leaveq 
  400695:	c3                   	retq   
  400696:	90                   	nop    
  400697:	90                   	nop    
Disassembly of section .fini:

0000000000400698 <_fini>:
  400698:	48 83 ec 08          	sub    $0x8,%rsp
  40069c:	e8 ff fd ff ff       	callq  4004a0 <__do_global_dtors_aux>
  4006a1:	48 83 c4 08          	add    $0x8,%rsp
  4006a5:	c3                   	retq   
