# TestControl.rb
class TestControl

    MAX_CALL_STACK = 10

    def initialize
        @m_curfunc = nil
        @m_nextfunc = nil
        @m_bNoWait = false

                      # 1   2   3   4   5   6   7   8   9   10
        @m_callstack = [nil,nil,nil,nil,nil,nil,nil,nil,nil,nil]
        @m_callstack_level = 0
    end

    def update
        while true 
            bFirst = true
            if @m_nextfunc != nil then
                @m_curfunc = @m_nextfunc
                @m_nextfunc = nil
                bFirst = true
            end

            @m_bNoWait = false
            if @m_curfunc != nil then
                @m_curfunc.call(bFirst)            
            end

            if @m_bNoWait == false then
                break
            end
        end
    end

    def goto(st)
        @m_nextfunc = st
    end

    def checkState(st)
        return @m_curfunc == st
    end

    def noWait
        @m_bNoWait = true
    end

    def hasNextState
        return @m_nextfunc != nil
    end

    def goSubState(sub,nex)
        if @m_callstack_level >= (MAX_CALL_STACK-1) then
            puts('CALL STACK OVER FLOW')
        else
            @m_callstack[@m_callstack_level] = nex
            @m_callstack_level += 1
            goto( sub )
        end
    end

    def returnState
        st = nil
        if @m_callstack_level <= 0 then
            puts('CALL STACK UNDER FLOW')
        else
            @m_callstack_level -= 1
            st = @m_callstack[@m_callstack_level]
            goto( st )
        end
    end

    def run
        puts "[START OF RUNNING]"
        puts ""
        
        goto(self.method(:S_START))
        loopmax = 50000
        loopmax.times do |count|
            if count >= loopmax - 1 then
                puts "error : out of loop"
                break
            end
            update()
            if checkState(self.method(:S_END)) then
                puts ""
                puts "[END OF RUNNING]"
                break
            end
        end
    end

    # Embed code
    # [STATEGO OUTPUT START] indent(4) $/^E_/$
    #             psggConverterLib.dll converted from psgg-file:TestControl.psgg

    #
    #    E_0001
    #
    #
    TITLE="Ruby Sample using StateGo."


    # [STATEGO OUTPUT END]

    # State methods
    # [STATEGO OUTPUT START] indent(4) $/^S_/$
    #             psggConverterLib.dll converted from psgg-file:TestControl.psgg

    #
    #    S_1st
    #
    #
    def S_1st(bFirst)
        if bFirst then
            puts("1st")
        end
        if hasNextState() == false then
            goto(self.method(:S_RET001))
        end
    end
    #
    #    S_2nd
    #
    #
    def S_2nd(bFirst)
        if bFirst then
            puts( "2nd" )
        end
        if hasNextState() == false then
            goto(self.method(:S_RET001))
        end
    end
    #
    #    S_END
    #
    #
    def S_END(bFirst)
        # nothing
    end
    #
    #    S_GET_RANDOM
    #    乱数取得
    #
    def S_GET_RANDOM(bFirst)
        @x = rand(10)
        if @x == 0 then
            goto( self.method(:S_Zero) )
        elsif @x == 1 then
            goto( self.method(:S_1st) )
        elsif @x == 2 then
            goto( self.method(:S_2nd) )
        else
            goto( self.method(:S_Others) )
        end
    end
    #
    #    S_GSB000
    #
    #
    def S_GSB000(bFirst)
        goSubState(self.method(:S_SBS000), self.method(:S_PAS000))
        noWait()
    end
    #
    #    S_HELLOWORLD
    #
    #
    def S_HELLOWORLD(bFirst)
        if bFirst then
            puts("Hello World.")
        end
        if hasNextState() == false then
            goto(self.method(:S_HELLOWORLD1))
        end
    end
    #
    #    S_HELLOWORLD1
    #
    #
    def S_HELLOWORLD1(bFirst)
        if bFirst then
            puts(TITLE)
        end
        if hasNextState() == false then
            goto(self.method(:S_GSB000))
        end
    end
    #
    #    S_LOP000
    #
    #
    def S_LOP000(bFirst)
        @m_index = 0
        goto(self.method(:S_LOP000_cond____))
        noWait()
    end
    def S_LOP000_cond____(bFirst)
        if @m_index < 10 then
            goSubState(self.method(:S_SBS001),self.method(:S_LOP000_next____))
        else
            goto(self.method(:S_END))
        end
        noWait()
    end
    def S_LOP000_next____(bFirst)
        @m_index += 1
        goto(self.method(:S_LOP000_cond____));
        noWait()
    end
    #
    #    S_Others
    #
    #
    def S_Others(bFirst)
        if bFirst then
            puts(@x)
        end
        if hasNextState() == false then
            goto(self.method(:S_RET001))
        end
    end
    #
    #    S_PAS000
    #
    #
    def S_PAS000(bFirst)
        if hasNextState() == false then
            goto(self.method(:S_RAND_INIT))
        end
    end
    #
    #    S_RAND_INIT
    #    乱数初期化
    #
    def S_RAND_INIT(bFirst)
        if bFirst then
            srand(Time.now.tv_sec)
        end
        if hasNextState() == false then
            goto(self.method(:S_LOP000))
        end
    end
    #
    #    S_RET000
    #
    #
    def S_RET000(bFirst)
        returnState()
        noWait()
    end
    #
    #    S_RET001
    #
    #
    def S_RET001(bFirst)
        returnState()
        noWait()
    end
    #
    #    S_SBS000
    #
    #
    def S_SBS000(bFirst)
        goto(self.method(:S_SUBROUTINE))
        noWait()
    end
    #
    #    S_SBS001
    #
    #
    def S_SBS001(bFirst)
        goto(self.method(:S_START_LOOP))
        noWait()
    end
    #
    #    S_START
    #
    #
    def S_START(bFirst)
        goto(self.method(:S_HELLOWORLD))
        noWait()
    end
    #
    #    S_START_LOOP
    #
    #
    def S_START_LOOP(bFirst)
        if bFirst then
            print( "Loop :", @m_index, ", rand num =>" )
        end
        if hasNextState() == false then
            goto(self.method(:S_GET_RANDOM))
        end
    end
    #
    #    S_SUBROUTINE
    #
    #
    def S_SUBROUTINE(bFirst)
        if bFirst then
            puts('This is the subroutine.' )
        end
        if hasNextState() == false then
            goto(self.method(:S_RET000))
        end
    end
    #
    #    S_Zero
    #
    #
    def S_Zero(bFirst)
        if bFirst then
            puts("Zero")
        end
        if hasNextState() == false then
            goto(self.method(:S_RET001))
        end
    end


    # [STATEGO OUTPUT END]
end