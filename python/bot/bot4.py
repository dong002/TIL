from typing import Awaitable
import discord,asyncio
from discord import member
from discord.ext import commands
mode=0
bot = commands.Bot(command_prefix='!')
ct = discord.Client()

@ct.event
async def on_ready():
    print(f'{bot.user} 에 로그인하였습니다!')

# @bot.command()
# async def 오하요(ctx):
#     await ctx.send('곤니찌와')
# # @bot.event()
# # async def on_member_join(mem):
# #     await member.send('와따시다치노 서버에 이랏샤이마셍')
# @bot.command()
# async def 따라해(ctx,*,content):
#     await ctx.reply(content)

# @bot.command()
# async def 반복해(ctx,i,*,content):
#     j=0
#     mum=0
#     for j in range(int(i)):
#         await ctx.reply(content)
#         if mum==1:
#             break
# @ct.event()
# async def on_message(ctx):
#     await ctx.send("시작이요 히히")
#     mode=1
# #     while(ctx != '끝'):
# #         await ct.wait_for('ctx')
# #         await ctx.channel.send("ㅇㅇ")
# @ct.event()
# async def on_message(ctx):
#     await ctx.send("its over.. go home")
#     mode=0
# @bot.command()
# async def 대화시작(ctx):
#     await ctx.send("대화를 시작합니당")
#     mode=1
# @bot.command()
# async def 대화끝(ctx):
#     await ctx.send("대화를 끝내농")
#     mode=0
@ct.event
async def on_message(ctx):
    ch = ctx.channel
    # if ctx.content.startwith("대화시작"):
    #     await ch.send("시작이요 히히")
    # # msg = await ct.wait_for('ctx')
    # if mode == 1:
    await ch.send("ㅇㅇ")
    # await ctx.send("ㅇㅇ")





ct.run('ODk0NzYxNDAxMTQ5NzAyMjA1.YVutfQ.ESXVGq_G4iPPOebW3sH1XbOoyrc')